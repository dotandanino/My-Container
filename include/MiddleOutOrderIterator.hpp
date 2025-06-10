//dotandanino@gmail.com
#ifndef MIDDLE_OUT_ORDER_ITERATOR_HPP
#define MIDDLE_OUT_ORDER_ITERATOR_HPP
#include <iostream>
#include <vector>
#include "MyContainer.hpp"


using std::vector;
using std::cout;
using std::endl;

namespace containers
{
    template <typename T>
    class MiddleOutOrderIterator {
    private:
        const MyContainer<T>& cont;
        vector<size_t> indices;// Vector to hold indices of the elements in the container
        size_t current;

    public:
        /**
         * @brief MiddleOutOrderIterator is an iterator for MyContainer that iterates over the elements in a middle-out order.
         * The order starts from the middle of the container and alternates between left and right sides.
         * @param c The MyContainer to iterate over.
         * @param begin If true, initializes the iterator to the beginning; if false, initializes to the end.
         */
        MiddleOutOrderIterator(const MyContainer<T>& c, bool begin = true) : cont(c), current(0) {
            int left=cont.container.size()/2-1;// int and not size_t because i want to check if left is negative
            size_t right=cont.container.size()/2;
            bool rightside=true;//i want to start with the right side
            while((right<cont.container.size() && rightside) || (left >= 0 && !rightside)) {
                if (rightside) {
                    indices.push_back(right);
                    right++;
                } else {
                    indices.push_back(left);
                    left--;
                }
                rightside = !rightside;
            }
            
            if (!begin)//for the end iterator
                current = indices.size();
        }
        /**
         * @brief Access an element by index.
         * @param index The index of the element to access.
         * @return The element at the specified index.
         * @throw std::out_of_range if the index is out of range.
         * @note I return const T& to avoid copying the element, which is more efficient for large objects. and also avoid changing the element.
         */
        const T& operator[](size_t index) const {
            if(index >= indices.size()) {//no need to check for negative index because indices type is size_t
                throw std::out_of_range("Index out of range");
            }
            return cont.container[indices[index]];
        }
        /**
         * @brief return the current element.
         * @return The current element in the iteration.
         * @throw std::out_of_range if the iterator is out of range.
         * @note I return const T& to avoid copying the element, which is more efficient for large objects. and also avoid changing the element.
         */
        const T& operator*() const {
            if(current>=indices.size() || current < 0) {
                throw std::out_of_range("Iterator out of range");
            }
            return cont.container[indices[current]];
        }
        /**
         * @brief prefix-increment operator to move to the next element.
         * @return A reference to the current iterator.
         */
        MiddleOutOrderIterator& operator++() {
            ++current;
            return *this;
        }
        /**
         * @brief postfix-increment operator to move to the next element.
         * @return A copy of the current iterator before incrementing.
         * @note This is a postfix increment operator, which means it returns the current state before incrementing.
         */
        MiddleOutOrderIterator operator++(int){
            MiddleOutOrderIterator temp = *this;
            ++current;
            return temp;
        }
        /**
         * @brief compare two MiddleOutOrderIterator objects for equality. in use to check if begin != end
         * @param other The other MiddleOutOrderIterator to compare with.
         * @return true if the current element is not equal to the other element, false otherwise.
         */
        bool operator!=(const MiddleOutOrderIterator& other) const {
            return current != other.current || &cont != &other.cont;
        }

        /**
         * @brief compare two MiddleOutOrderIterator objects for equality. in use to check if begin != end
         * @param other The other MiddleOutOrderIterator to compare with.
         * @return true if the current element is equal to the other element, false otherwise.
         */
        bool operator==(const MiddleOutOrderIterator& other) const {
            return current == other.current && &cont == &other.cont;
        }
    };
            
}
#endif