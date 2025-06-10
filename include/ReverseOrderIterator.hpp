//dotandanino@gmail.com
#ifndef REVERSE_ORDER_ITERATOR_HPP
#define REVERSE_ORDER_ITERATOR_HPP
#include <iostream>
#include <vector>
#include "MyContainer.hpp"
using std::vector;
using std::cout;
using std::endl;
namespace containers
{
    template <typename T>
    /**
     * @brief ReverseOrderIterator is an iterator for MyContainer that iterates over the elements in reverse order.
     */
    class ReverseOrderIterator {
    private:
        const MyContainer<T>& cont;
        size_t current;

    public:
        /**
         * @brief Constructor for ReverseOrderIterator.
         * @param c The MyContainer to iterate over.
         * @param begin If true, initializes the iterator to the last element; if false, initializes to before the first element.
         */
        ReverseOrderIterator(const MyContainer<T>& c, bool begin = true) : cont(c){
            if(begin){
                current = cont.container.size() - 1; // Start from the last element
            } else {
                current = -1;
            }
        }
        /**
         * @brief Dereference operator to access the current element.
         * @return The current element in the iteration.
         * @throw std::out_of_range if the iterator is out of range.
         * @note I return const T& to avoid copying the element, which is more efficient for large objects. and also avoid changing the element.
         */
        const T& operator*() const {
            if(current >= cont.container.size() || current < 0) {
                throw std::out_of_range("Iterator out of range");
            }
            return cont.container[current];
        }
        /**
         * @brief Access operator to get the element at a specific index.
         * @param index The index of the element to access.
         * @return The element at the specified index.
         * @throw std::out_of_range if the index is out of range.
         * @note I return const T& to avoid copying the element, which is more efficient for large objects. and also avoid changing the element.
         */
        const T& operator[](size_t index) const {
            if(index >= cont.container.size()) {//no need to check for negative index because indices type is size_t
                throw std::out_of_range("Index out of range");
            }
            return cont.container[cont.container.size() - 1 - index]; // Accessing in reverse order
        }
        /**
         * @brief prefix-increment operator to move to the next element.
         * @return A reference to the current iterator.
         */
        ReverseOrderIterator& operator++() {
            --current;
            return *this;
        }
        /**
         * @brief postfix-increment operator to move to the next element.
         * @return A copy of the current iterator before incrementing.
         * @note This is a postfix increment operator, which means it returns the current state before incrementing.
         */
        ReverseOrderIterator operator++(int){
            ReverseOrderIterator temp = *this;
            --current;
            return temp;
        }
        /**
         * @brief Equality operator to compare two ReverseOrderIterator objects.
         * @param other The other ReverseOrderIterator to compare with.
         * @return true if the current position and container reference are the same, false otherwise.
         */
        bool operator!=(const ReverseOrderIterator& other) const {
            return current != other.current || &cont != &other.cont;
        }

        /**
         * @brief Equality operator to compare two ReverseOrderIterator objects.
         * @param other The other ReverseOrderIterator to compare with.
         * @return true if the current position and container reference are the same, false otherwise.
         */
        bool operator==(const ReverseOrderIterator& other) const {
            return current == other.current && &cont == &other.cont;
        }
    };


}

#endif