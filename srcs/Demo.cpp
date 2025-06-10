#include <iostream>
#include "../include/MyContainer.hpp"
#include "../include/AcsendingOrderIterator.hpp"
#include "../include/DescendingOrderIterator.hpp"
#include "../include/sideCrossOrderIterator.hpp"
#include "../include/ReverseOrderIterator.hpp"
#include "../include/OrderIterator.hpp"
#include "../include/MiddleOutOrderIterator.hpp"

using namespace containers;
int main() {
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);
    std::cout<<container;
    std::cout << "Size of container: " << container.size() << std::endl;
    std::cout << "Ascending Order:" << std::endl;
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        std::cout << *it << ' ';   // 1 2 6 7 15
    }
    std::cout << std::endl;
    std::cout << "Descending Order:" << std::endl;
    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it) {
        std::cout << *it << ' ';  // 15 7 6 2 1
    }
    std::cout << std::endl;
    std::cout << "Cross Side Order:" << std::endl;
    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it) {
        std::cout << *it << ' ';  // 1 15 2 7 6
    }
    std::cout << std::endl;
    std::cout << "Reverse Order:" << std::endl;
    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it) {
        std::cout << *it << ' ';  // 2 1 6 15 7
    }
    std::cout << std::endl;
    std::cout << "Order:" << std::endl;
    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        std::cout << *it << ' ';  // 7 15 6 1 2
    }
    std::cout << std::endl;
    std::cout << "Middle Out Order:" << std::endl;
    for (auto it = container.begin_middle_out_order(); it != container.end_middle_out_order(); ++it) {
        std::cout << *it << ' ';  // 6 15 1 7 2
    }
    std::cout << std::endl;

    

    return 0;
}
