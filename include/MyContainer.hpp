//dotandanino@gmail.com
#ifndef MY_CONTAINER_HPP
#define MY_CONTAINER_HPP
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
namespace containers
{
    template <typename T>
    class MyContainer;
    template <typename T> class AscendingOrderIterator;
    template <typename T> class DecendingOrderIterator;
    template <typename T> class CrossSideOrderIterator;
    template <typename T> class ReverseOrderIterator;
    template <typename T> class OrderIterator;
    template <typename T> class MiddleOutOrderIterator;
    template <typename T> 
    std::ostream& operator<<(std::ostream& output, const MyContainer<T>& cont);

    template <typename T = int>
    class MyContainer{
        friend class AscendingOrderIterator<T>;
        friend class DecendingOrderIterator<T>;
        friend class CrossSideOrderIterator<T>;
        friend class ReverseOrderIterator<T>;
        friend class OrderIterator<T>;
        friend class MiddleOutOrderIterator<T>;
        private:
            vector<T> container;
            public:
            /**
             * @brief Default constructor for MyContainer.
             * Initializes an empty container.
             */
            MyContainer()=default;
            /**
             * @brief add an item to the container.
             * @param item The item to be added to the container.
             * @note This function adds the item to the end of the container.
             */
            void addElement(const T& item){
                this->container.push_back(item);
            }

            /**
             * @brief remove an item from the container.
             * @param item The item to be removed from the container.
             * @throw std::runtime_error if the item is not found in the container.
             * @note This function removes all occurrences of the item from the container.
             */
            void remove(const T& item){
                bool found=false;
                auto start=container.begin();
                for(;start!=container.end();){
                    if((*start)==item){
                        container.erase(start);
                        found=true;
                    }else{
                        start++;
                    }
                }
                if(!found){
                    throw std::runtime_error("this item is not in the container");
                }
            }
            /**
             * @brief return the size of the container.
             * @return The number of elements in the container.
             */
            int size(){
                return container.size();
            }
            friend std::ostream& operator<< <>(std::ostream& output, const MyContainer<T>& container);
            /**
             * @brief begin for the ascending order iterator.
             * @return An AscendingOrderIterator pointing to the beginning of the container.
             */
            AscendingOrderIterator<T> begin_ascending_order() const {
                return AscendingOrderIterator<T>(*this, true);
            }
            /**
             * @brief end for the ascending order iterator.
             * @return An AscendingOrderIterator pointing to the end of the container.
             */
            AscendingOrderIterator<T> end_ascending_order() const {
                return AscendingOrderIterator<T>(*this, false);
            }
            /**
             * @brief begin for the descending order iterator.
             * @return A DecendingOrderIterator pointing to the beginning of the container.
             */
            DecendingOrderIterator<T> begin_descending_order() const {
                return DecendingOrderIterator<T>(*this, true);
            }
            /**
             * @brief end for the descending order iterator.
             * @return A DecendingOrderIterator pointing to the end of the container.
             */
            DecendingOrderIterator<T> end_descending_order() const {
                return DecendingOrderIterator<T>(*this, false);
            }
            /**
             * @brief begin for the cross side order iterator.
             * @return A CrossSideOrderIterator pointing to the beginning of the container.
             */
            CrossSideOrderIterator<T> begin_side_cross_order() const {
                return CrossSideOrderIterator<T>(*this, true);
            }
            /**
             * @brief end for the cross side order iterator.
             * @return A CrossSideOrderIterator pointing to the end of the container.
             */
            CrossSideOrderIterator<T> end_side_cross_order() const {
                return CrossSideOrderIterator<T>(*this, false);
            }
            /**
             * @brief begin for the reverse order iterator.
             * @return A ReverseOrderIterator pointing to the beginning of the container.
             */
            ReverseOrderIterator<T> begin_reverse_order() {
                return ReverseOrderIterator<T>(*this, true);
            }
            /**
             * @brief end for the reverse order iterator.
             * @return A ReverseOrderIterator pointing to the end of the container.
             */
            ReverseOrderIterator<T> end_reverse_order() {
                return ReverseOrderIterator<T>(*this, false);
            }
            /**
             * @brief begin for the order iterator.
             * @return An OrderIterator pointing to the beginning of the container.
             */
            OrderIterator<T> begin_order() {
                return OrderIterator<T>(*this, true);
            }
            /**
             * @brief end for the order iterator.
             * @return An OrderIterator pointing to the end of the container.
             */
            OrderIterator<T> end_order() {
                return OrderIterator<T>(*this, false);
            }
            /**
             * @brief begin for the middle out order iterator.
             * @return A MiddleOutOrderIterator pointing to the beginning of the container.
             */
            MiddleOutOrderIterator<T> begin_middle_out_order() {
                return MiddleOutOrderIterator<T>(*this, true);
            }
            /**
             * @brief end for the middle out order iterator.
             * @return A MiddleOutOrderIterator pointing to the end of the container.
             */
            MiddleOutOrderIterator<T> end_middle_out_order() {
                return MiddleOutOrderIterator<T>(*this, false);
            }

    };
    template<typename T>
    /**
     * @brief Overloaded output operator for MyContainer.
     * @param output The output stream to write to.
     * @param cont The MyContainer object to be printed.
     * @return The output stream after writing the container's contents.
     */
    std::ostream& operator<<(std::ostream& output, const MyContainer<T>& cont){
        output << "[";
        for(size_t i = 0; i < cont.container.size(); ++i) {
            output << cont.container[i];
            if(i < cont.container.size() - 1) output << ", ";
        }
        output << "]"<<endl;
        return output;
    }


} // namespace containers

#endif