//dotandanino@gmail.com
#ifndef DESCENDING_ORDER_ITERATOR_HPP
#define DESCENDING_ORDER_ITERATOR_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include "MyContainer.hpp"


using std::vector;
using std::cout;
using std::endl;

namespace containers
{
    template <typename T>
    class DecendingOrderIterator {
    private:
        /**
         * @brief A comparison functor for sorting indices based on the values in the container in descending order.
         */
        class DescendingCompare {
            const vector<T>& data;
            public:
                /**
                 * @brief Constructor for DescendingCompare.
                 * @param d The vector of data to compare.
                 */
                DescendingCompare(const vector<T>& d) : data(d) {}
                
                bool operator()(size_t i, size_t j) const {
                    return data[i] > data[j];
                }
            };
        const MyContainer<T>& cont;
        vector<size_t> indices;
        size_t current;

    public:
        /**
         * @brief Constructor for DecendingOrderIterator.
         * @param c The MyContainer to iterate over.
         * @param begin If true, initializes the iterator to the beginning; if false, initializes to the end.
         */
        DecendingOrderIterator(const MyContainer<T>& c, bool begin = true) : cont(c), current(0) {
            indices.resize(cont.container.size());
            for (size_t i = 0; i < cont.container.size(); ++i)
                indices[i] = i;

            std::sort(indices.begin(), indices.end(), DescendingCompare(cont.container));

            if (!begin)
                current = indices.size();
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
         * @brief Access an element by index.
         * @param index The index of the element to access.
         * @return The element at the specified index.
         * @note I return const T& to avoid copying the element, which is more efficient for large objects. and also avoid changing the element.
         * @throw std::out_of_range if the index is out of range.
         */
        const T& operator[](size_t index) const {
            if(index >= indices.size()) {//no need to check for negative index because indices type is size_t
                throw std::out_of_range("Index out of range");
            }
            return cont.container[indices[index]];
        }

        /**
         * @brief prefix-increment operator to move to the next element.
         * @return A reference to the current iterator.
         */
        DecendingOrderIterator& operator++() {
            ++current;
            return *this;
        }

        /**
         * @brief postfix-increment operator to move to the next element.
         * @return A copy of the current iterator before incrementing.
         * @note This is a postfix increment operator, which means it returns the current state before incrementing.
         */
        DecendingOrderIterator operator++(int){
            DecendingOrderIterator temp = *this;
            ++current;
            return temp;
        }

        /**
         * @brief Checks if the iterator has reached the end.
         * @return true if the iterator is at the end, false otherwise.
         */
        bool operator!=(const DecendingOrderIterator& other) const {
            return current != other.current || &cont != &other.cont;
        }

        /**
         * @brief Equality operator to compare two DecendingOrderIterator objects.
         * @param other The other DecendingOrderIterator to compare with.
         * @return true if the current position and container reference are the same, false otherwise.
         */
        bool operator==(const DecendingOrderIterator& other) const {
            return current == other.current && &cont == &other.cont;
        }
    };
}
#endif