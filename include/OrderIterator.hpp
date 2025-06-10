//dotandanino@gmail.com
#ifndef ORDER_ITERATOR_HPP
#define ORDER_ITERATOR_HPP
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
     * @brief OrderIterator is an iterator for MyContainer that iterates over the elements in order.
     */
    class OrderIterator {
    private:
        const MyContainer<T>& cont;
        size_t current;

    public:
        /**
         * @brief Constructor for OrderIterator.
         * @param c The MyContainer to iterate over.
         * @param begin If true, initializes the iterator to the beginning; if false, initializes to the end.
         */
        OrderIterator(const MyContainer<T>& c, bool begin = true) : cont(c){
            if(begin){
                current =  0; // Start from the first element
            } else {
                current = cont.container.size();
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
            return cont.container[index];
        }
        /**
         * @brief prefix-increment operator to move to the next element.
         * @return A reference to the current iterator.
         */
        OrderIterator& operator++() {
            ++current;
            return *this;
        }
        /**
         * @brief postfix-increment operator to move to the next element.
         * @return A copy of the current iterator before incrementing.
         * @note This is a postfix increment operator, which means it returns the current state before incrementing.
         */
        OrderIterator operator++(int){
            OrderIterator temp = *this;
            ++current;
            return temp;
        }
        /**
         * @brief compare two AscendingOrderIterator objects for equality. in use to check if begin != end
         * @param other The other AscendingOrderIterator to compare with.
         * @return true if the current element is not equal to the other element, false otherwise.
         */
        bool operator!=(const OrderIterator& other) const {
            return current != other.current || &cont != &other.cont;
        }

        /**
         * @brief Compares two OrderIterator objects for equality.
         * @param other The other OrderIterator to compare with.
         * @return true if the current position and container reference are the same, false otherwise.
         */
        bool operator==(const OrderIterator& other) const {
            return current == other.current && &cont == &other.cont;
        }
    };


}

#endif