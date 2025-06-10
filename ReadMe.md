
My Container assignment

# student information:
- name: dotan danino
- id 328144951
- gmail: dotandanino@gmail.com
# project information:
- In this project i had implemnted a class my container that can hold any type of comparable objects and can iterate over them in different orders.
- I have this iterators 
    - AscendingOrderIterator
    - DescendingOrderIterator
    - MiddleOutOrderIterator
    - OrderIterator
    - ReverseOrderIterator
    - SideCrossOrderIterator
here is an explanation of each one and example of the order they iterate over the container [7,15,6,1,2]:
    

| **Iterator**                | **Explanation**                                                    | **Example**                         |
|----------------------------|---------------------------------------------------------------------|-------------------------------------|
| `AscendingOrderIterator`   | Iterates over the container in ascending order                      | `[1, 2, 6, 7, 15]`                  |
| `DescendingOrderIterator`  | Iterates over the container in descending order                     | `[15, 7, 6, 2, 1]`                  |
| `MiddleOutOrderIterator`   | Iterates from the middle outwards alternately left and right        | `[6, 15, 1, 7, 2]`                  |
| `OrderIterator`            | Iterates in the order elements were added to the container          | `[7, 15, 6, 1, 2]`                  |
| `ReverseOrderIterator`     | Iterates in reverse of the insertion order                          | `[2, 1, 6, 15, 7]`                  |
| `SideCrossOrderIterator`   | Alternates between start and end, moving inward from both sides     | `[1, 15, 2, 7, 6]`                  |



- there is three ways to run this project you can run the main or the test or to run valgrind on both of then.
    #### run Demo
    - to run main first time you need to write the next commands:
        - make Main
    - after you build the files you can write: ./Main
    #### run test
    - to run test you need to write the next commands:
        - make test
    #### run valgrind
    - to run valgrind(on both Demo and test) you need to write the next commands:
        - make valgrind
    

# files namespace and classes
### Files:
    ├── ReadMe.md
├── include
│   ├── AcsendingOrderIterator.hpp
│   ├── DescendingOrderIterator.hpp
│   ├── MiddleOutOrderIterator.hpp
│   ├── MyContainer.hpp
│   ├── OrderIterator.hpp
│   ├── ReverseOrderIterator.hpp
│   ├── doctest.h
│   ├── sideCrossOrderIterator.hpp
│   └── tempClass.hpp
├── makefile
└── srcs
    ├── Demo.cpp
    ├── tempClass.cpp
    └── test.cpp
    

### Classes:
    - MyContainer
    - AscendingOrderIterator
    - DescendingOrderIterator
    - MiddleOutOrderIterator
    - OrderIterator
    - ReverseOrderIterator
    - sideCrossOrderIterator
    - tempClass - a class that i used to test the iterators to show they work correctly with every comperable object

### Data Structures:
    i didnt need to build any Data Structures to this project 
### NameSpace
    all the project is under the name space containers