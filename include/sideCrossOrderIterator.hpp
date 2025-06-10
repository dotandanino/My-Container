//dotandanino@gmail.com
#ifndef CROSS_SIDE_ORDER_ITERATOR_HPP
#define CROSS_SIDE_ORDER_ITERATOR_HPP
#include <iostream>
#include <vector>
#include <algorithm>//in use for std::sort
#include "MyContainer.hpp"


using std::vector;
using std::cout;
using std::endl;

namespace containers
{
    template <typename T>
    class CrossSideOrderIterator {
    private:
        /**
         * @brief A comparison functor for sorting indices based on the values in the container.
         */
        class AscendingCompare {
            const vector<T>& data;
        public:
            /**
             * @brief Constructor for AscendingCompare.
             * @param d The vector of data to compare.
             */
            AscendingCompare(const vector<T>& d) : data(d) {}
            bool operator()(size_t i, size_t j) const {
                return data[i] < data[j];
            }
        };
        const MyContainer<T>& cont;
        vector<size_t> indices;// Vector to hold indices of the elements in the container
        size_t current;

    public:
        /**
         * @brief Constructor for CrossSideOrderIterator.
         * @param c The MyContainer to iterate over.
         * @param begin If true, initializes the iterator to the beginning; if false, initializes to the end.
         */
        CrossSideOrderIterator(const MyContainer<T>& c, bool begin = true) : cont(c), current(0) {
            vector<size_t> temp;
            temp.resize(cont.container.size());
            for (size_t i = 0; i < cont.container.size(); ++i)
                temp[i] = i;

            std::sort(temp.begin(), temp.end(), AscendingCompare(cont.container));
            int left=0;
            int right=cont.container.size()-1;
            bool leftide=true;//from the example i want to start with the left side
            while(left<=right){
                if(leftide){//every time i push only 1 side
                    indices.push_back(temp[left]);
                    left++;
                }else{
                    indices.push_back(temp[right]);
                    right--;
                }
                leftide=!leftide;
            }
            
            if (!begin)//for the end iterator
                current = indices.size();
        }
        

        /**
         * @brief return the current element.
         * @return The current element in the iteration.
         * @throw std::out_of_range if the iterator is out of range.
         * @note I return const T& to avoid copying the element, which is more efficient for large objects. and also avoid changing the element.
         */
        const T& operator*() const {
            if(current >= indices.size() || current < 0) {
                throw std::out_of_range("Iterator out of range");
            }
            return cont.container[indices[current]];
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
         * @brief prefix-increment operator to move to the next element.
         * @return A reference to the current iterator.
         */
        CrossSideOrderIterator& operator++() {
            ++current;
            return *this;
        }

        /**
         * @brief postfix-increment operator to move to the next element.
         * @return A copy of the current iterator before incrementing.
         * @note This is a postfix increment operator, which means it returns the current state before incrementing.
         */
        CrossSideOrderIterator operator++(int){
            CrossSideOrderIterator temp = *this;
            ++current;
            return temp;
        }
        /**
         * @brief Compares two CrossSideOrderIterator objects for equality.
         * @param other The other CrossSideOrderIterator to compare with.
         * @return true if the current position and container reference are the same, false otherwise.
         */
        bool operator==(const CrossSideOrderIterator& other) const {
            return current == other.current && &cont == &other.cont;
        }
        /**
         * @brief Compares two CrossSideOrderIterator objects for inequality.
         * @param other The other CrossSideOrderIterator to compare with.
         * @return true if the current position or container reference is different, false otherwise.
         */
        bool operator!=(const CrossSideOrderIterator& other) const {
            return current != other.current || &cont != &other.cont;
        }
    };
            
}
#endif