//dotandanino@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/MyContainer.hpp"
#include "../include/AcsendingOrderIterator.hpp"
#include "../include/DescendingOrderIterator.hpp"
#include "../include/sideCrossOrderIterator.hpp"
#include "../include/ReverseOrderIterator.hpp"
#include "../include/OrderIterator.hpp"
#include "../include/MiddleOutOrderIterator.hpp"
#include "../include/tempClass.hpp"
using namespace containers;
using std::vector;
using std::string;
/**
 * @brief Test cases for MyContainer class.  
*/
TEST_CASE("MyContainer"){
    
    /**
     * @brief Subcase for empty container including remove, size, and output operator.
     */
    SUBCASE("Empty Container - remove , size ,<<"){
        MyContainer<string> container;
        CHECK(container.size()==0);
        CHECK_THROWS_WITH(container.remove("nothing to remove"),"this item is not in the container");//cant remove from empty container;
        string expected = "[]\n";
        std::ostringstream output;
        output<<container;
        CHECK(expected == output.str());
    }
    
    /**
    * @brief subcase for the remove function try to remove an item that is not in the container.
    */
    SUBCASE("remove non existing item"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        CHECK_THROWS_WITH(container.remove(100), "this item is not in the container");//cant remove non existing item from the container;
        CHECK_NOTHROW(container.remove(15));//remove existing item
    }
    
    /**
     * @brief Subcase for adding elements and checking the size of the container.
     */
    SUBCASE("addElement + size"){
        MyContainer<int> container;
        CHECK(container.size()==0);
        container.addElement(7);
        CHECK(container.size()==1);
        container.addElement(15);
        CHECK(container.size()==2);
        container.addElement(6);
        CHECK(container.size()==3);
        container.addElement(1);
        CHECK(container.size()==4);
        container.addElement(2);
        CHECK(container.size()==5);
        container.addElement(12);
        CHECK(container.size()==6);
        container.addElement(8);
        CHECK(container.size()==7);
        container.addElement(2005);
        CHECK(container.size()==8);
    }

    /**
     * @brief Subcase for the output operator (<<) of MyContainer.
     */
    SUBCASE("<<"){
        MyContainer<int> container;
        container.addElement(7);
        string expected = "[7]\n";
        std::ostringstream output;
        output << container;
        container.addElement(15);
        expected = "[7, 15]\n";
        output.str(""); // Clear the output stream
        output << container;
        CHECK(expected == output.str());
        container.addElement(6);
        expected = "[7, 15, 6]\n";
        output.str(""); // Clear the output stream
        output << container;
        CHECK(expected == output.str());
        container.addElement(1);
        expected = "[7, 15, 6, 1]\n";
        output.str(""); // Clear the output stream
        output << container;
        CHECK(expected == output.str());
        container.addElement(2);
        expected = "[7, 15, 6, 1, 2]\n";
        output.str(""); // Clear the output stream
        output << container;
        CHECK(expected == output.str());
    }

    /**
     * @brief Subcase for the remove function of MyContainer. check a lot of remove situations.
     */
    SUBCASE("remove"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);
        string expected = "[7, 15, 6, 1, 2]\n";
        std::ostringstream output;
        output << container;
        CHECK(expected == output.str());
        CHECK(container.size() == 5);
        
        container.remove(15);
        expected = "[7, 6, 1, 2]\n";
        output.str(""); // Clear the output stream
        output << container;
        CHECK(expected == output.str());
        CHECK(container.size() == 4);
        
        container.remove(1);
        expected = "[7, 6, 2]\n";
        output.str(""); // Clear the output stream
        output << container;
        CHECK(expected == output.str());
        CHECK(container.size() == 3);
        
        CHECK_THROWS_WITH(container.remove(100), "this item is not in the container");

        container.remove(2);
        expected = "[7, 6]\n";
        output.str(""); // Clear the output stream
        output << container;
        CHECK(expected == output.str());
        CHECK(container.size() == 2);

        container.remove(7);
        expected = "[6]\n";
        output.str(""); // Clear the output stream
        output << container;
        CHECK(expected == output.str());
        CHECK(container.size() == 1);

        container.remove(6);
        expected = "[]\n";
        output.str(""); // Clear the output stream
        output << container;
        CHECK(expected == output.str());
        CHECK(container.size() == 0);

        CHECK_THROWS_WITH(container.remove(6), "this item is not in the container");

        container.addElement(2);
        container.addElement(2);
        container.addElement(10);
        container.addElement(2);
        container.addElement(5);
        container.addElement(2);
        container.addElement(12);
        container.addElement(8);
        container.addElement(2005);
        container.addElement(2);
        expected = "[2, 2, 10, 2, 5, 2, 12, 8, 2005, 2]\n";
        output.str(""); // Clear the output stream
        output << container;
        CHECK(expected == output.str());
        CHECK(container.size() == 10);

        container.remove(2);
        expected = "[10, 5, 12, 8, 2005]\n";
        output.str(""); // Clear the output stream
        output << container;
        CHECK(expected == output.str());
        CHECK(container.size() == 5);


        container.remove(10);
        container.remove(5);
        container.remove(12);
        container.remove(8);
        container.remove(2005);
        CHECK(container.size() == 0);

        container.addElement(7);
        container.addElement(7);
        container.addElement(7);
        container.addElement(7);
        container.addElement(7);
        container.remove(7);
        expected = "[]\n";
        output.str(""); // Clear the output stream
        output << container;
        CHECK(expected == output.str());
        CHECK(container.size() == 0);
    }

    /**
     * @brief subcase for building container that contains double.
     */
    SUBCASE("double"){
        MyContainer<double> container;
        container.addElement(7.5);
        container.addElement(15.2);
        container.addElement(6.3);
        container.addElement(1.1);
        container.addElement(2.8);
        string expected = "[7.5, 15.2, 6.3, 1.1, 2.8]\n";
        std::ostringstream output;
        output << container;
        CHECK(expected == output.str());
        CHECK(container.size() == 5);
    }

    /**
     * @brief subcase for building container that contains string.
     */
    SUBCASE("string"){
        MyContainer<string> container;
        container.addElement("sharon");
        container.addElement("shay");
        container.addElement("ori");
        container.addElement("dotan");
        container.addElement("yonathan");
        string expected = "[sharon, shay, ori, dotan, yonathan]\n";
        std::ostringstream output;
        output << container;
        CHECK(expected == output.str());
        CHECK(container.size() == 5);
    }

    /**
     * @brief subcase for building container that contains TempClass - special for the test cases.
     *  a comperable class becuase this shoul work on every comperable class.
     */
    SUBCASE("TempClass"){
        MyContainer<TempClass> container;
        container.addElement(TempClass(28, 11.75, "sharon"));
        container.addElement(TempClass(15, 2.5, "shay"));
        container.addElement(TempClass(6, 3.5, "ori"));
        container.addElement(TempClass(1, 4.5, "dotan"));
        container.addElement(TempClass(2, 5.5, "yonathan"));
        CHECK(container.size() == 5);
    }
}

/**
 * @brief Test cases for Ascending Order Iterator.
 */
TEST_CASE("Ascending Order"){
    /**
     * @brief test the Ascending order iterator on the example from the github readMe page.
     */
    SUBCASE("git hub example"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);

        auto begin = container.begin_ascending_order();
        auto end = container.end_ascending_order();
        std::vector<int> expected = {1, 2, 6, 7, 15};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
        
    }

    /**
     * @brief test the Ascending order iterator on container with duplicate numbers.
     */
    SUBCASE("Ascending order - with equals number"){
        MyContainer<int>  container ;
        container.addElement(17);
        container.addElement(8);
        container.addElement(1971);
        container.addElement(28);
        container.addElement(11);
        container.addElement(1975);
        container.addElement(25);
        container.addElement(12);
        container.addElement(2003);
        container.addElement(12);
        container.addElement(8);
        container.addElement(2005);
        container.addElement(15);
        container.addElement(2);
        container.addElement(2007);
        std::vector<int> expected = {2, 8, 8, 11, 12, 12, 15, 17, 25, 28, 1971, 1975, 2003, 2005, 2007};
        auto begin = container.begin_ascending_order();
        auto end = container.end_ascending_order();
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
    /**
     * @brief test the Ascending order iterator on container with negative numbers.
     */
    SUBCASE("Ascending order - with negative numbers"){
        MyContainer<int>  container ;
        container.addElement(-17);
        container.addElement(8);
        container.addElement(-1971);
        container.addElement(28);
        container.addElement(11);
        container.addElement(-1975);
        container.addElement(25);
        container.addElement(12);
        container.addElement(2003);
        container.addElement(-12);
        container.addElement(8);
        container.addElement(2005);
        container.addElement(15);
        container.addElement(-2);
        container.addElement(2007);
        std::vector<int> expected = {-1975, -1971, -17, -12, -2, 8, 8, 11, 12, 15, 25, 28, 2003, 2005, 2007};
        auto begin = container.begin_ascending_order();
        auto end = container.end_ascending_order();
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Ascending order iterator on container with strings.
     */
    SUBCASE("string"){
        MyContainer<string> container;
        container.addElement("sharon");
        container.addElement("shay");
        container.addElement("ori");
        container.addElement("dotan");
        container.addElement("yonathan");
        container.addElement("danino");


        auto begin = container.begin_ascending_order();
        auto end = container.end_ascending_order();
        std::vector<string> expected = {"danino", "dotan", "ori", "sharon", "shay", "yonathan"};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Ascending order iterator on container with TempClass.
     */
    SUBCASE("TempClass"){
        MyContainer<TempClass> container;
        container.addElement(TempClass(28, 11.75, "sharon"));
        container.addElement(TempClass(15, 2.5, "shay"));
        container.addElement(TempClass(6, 3.5, "ori"));
        container.addElement(TempClass(1, 4.5, "dotan"));
        container.addElement(TempClass(2, 5.5, "yonathan"));
        container.addElement(TempClass(1, 1.5, "danino"));
        container.addElement(TempClass(1,1.5,"dotan"));

        auto begin = container.begin_ascending_order();
        auto end = container.end_ascending_order();
        std::vector<TempClass> expected = {
            TempClass(1, 1.5, "danino"),
            TempClass(1, 1.5, "dotan"),
            TempClass(1, 4.5, "dotan"),
            TempClass(2, 5.5, "yonathan"),
            TempClass(6, 3.5, "ori"),
            TempClass(15, 2.5, "shay"),
            TempClass(28, 11.75, "sharon")
        };
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Ascending order iterator operator[].
     */
    SUBCASE("[]"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);

        auto begin = container.begin_ascending_order();
        auto end = container.end_ascending_order();
        CHECK_THROWS_WITH(begin[6],"Index out of range");
        CHECK_THROWS_WITH(end[6],"Index out of range");
        CHECK_THROWS_WITH(begin[-1],"Index out of range");
        CHECK_THROWS_WITH(end[-1],"Index out of range");
        std::vector<int> expected = {1, 2, 6, 7, 15};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(begin[i] == expected[i]);
            CHECK(begin[i] == *begin);//make sure operator* and operator[i] are the same
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Ascending order iterator on empty container.
     */
    SUBCASE("Empty container"){
        MyContainer<double> container;
        auto beginA = container.begin_ascending_order();
        auto endA = container.end_ascending_order();
        CHECK_THROWS_WITH(*beginA, "Iterator out of range");
        CHECK_THROWS_WITH(*endA, "Iterator out of range");
    }

    /**
     * @brief test the Ascending order iterator on container with double.
     */
    SUBCASE("double"){
        MyContainer<double> container;
        container.addElement(7.5);
        container.addElement(15.2);
        container.addElement(6.3);
        container.addElement(1.1);
        container.addElement(2.4);

        auto begin = container.begin_ascending_order();
        auto end = container.end_ascending_order();
        std::vector<double> expected = {1.1, 2.4, 6.3, 7.5, 15.2};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
}

/**
 * @brief Test cases for Descending Order Iterator.
 */
TEST_CASE("Descending Order"){
    /**
     * @brief test the Descending order iterator on the example from the github readMe page.
     */
    SUBCASE("git hub example"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);

        auto begin = container.begin_descending_order();
        auto end = container.end_descending_order();
        std::vector<int> expected = {15, 7, 6, 2, 1};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
        
    }
    /**
     * @brief test the Descending order iterator on container with duplicate numbers.
     */
    SUBCASE("Descending order - with equals number"){
        MyContainer<int>  container ;
        container.addElement(17);
        container.addElement(8);
        container.addElement(1971);
        container.addElement(28);
        container.addElement(11);
        container.addElement(1975);
        container.addElement(25);
        container.addElement(12);
        container.addElement(2003);
        container.addElement(12);
        container.addElement(8);
        container.addElement(2005);
        container.addElement(15);
        container.addElement(2);
        container.addElement(2007);
        std::vector<int> expected = {2007, 2005, 2003, 1975, 1971, 28, 25, 17, 15, 12, 12, 11, 8, 8, 2};
        auto begin = container.begin_descending_order();
        auto end = container.end_descending_order();
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
    /**
     * @brief test the Descending order iterator on container with negative numbers.
     */
    SUBCASE("Descending order - with negative numbers"){
        MyContainer<int>  container ;
        container.addElement(-17);
        container.addElement(8);
        container.addElement(-1971);
        container.addElement(28);
        container.addElement(11);
        container.addElement(-1975);
        container.addElement(25);
        container.addElement(12);
        container.addElement(2003);
        container.addElement(-12);
        container.addElement(8);
        container.addElement(2005);
        container.addElement(15);
        container.addElement(-2);
        container.addElement(2007);
        std::vector<int> expected = {2007, 2005, 2003, 28, 25, 15, 12, 11, 8, 8, -2, -12, -17, -1971, -1975};
        auto begin = container.begin_descending_order();
        auto end = container.end_descending_order();
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
    /**
     * @brief test the Descending order iterator on container with strings.
     */
    SUBCASE("string"){
        MyContainer<string> container;
        container.addElement("sharon");
        container.addElement("shay");
        container.addElement("ori");
        container.addElement("dotan");
        container.addElement("yonathan");
        container.addElement("danino");
        container.addElement("dotan");
        auto begin = container.begin_descending_order();
        auto end = container.end_descending_order();
        std::vector<string> expected = {"yonathan",  "shay","sharon", "ori", "dotan", "dotan", "danino"};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
    /**
     * @brief test the Descending order iterator on container with TempClass.
     *  a comparable class i build for the test because this should work on every comparable class.
     */
    SUBCASE("TempClass"){
        MyContainer<TempClass> container;
        container.addElement(TempClass(28, 11.75, "sharon"));
        container.addElement(TempClass(15, 2.5, "shay"));
        container.addElement(TempClass(6, 3.5, "ori"));
        container.addElement(TempClass(1, 4.5, "dotan"));
        container.addElement(TempClass(2, 5.5, "yonathan"));
        container.addElement(TempClass(1, 1.5, "danino"));
        container.addElement(TempClass(1,1.5,"dotan"));

        auto begin = container.begin_descending_order();
        auto end = container.end_descending_order();
        std::vector<TempClass> expected = {
            TempClass(28, 11.75, "sharon"),
            TempClass(15, 2.5, "shay"),
            TempClass(6, 3.5, "ori"),
            TempClass(2, 5.5, "yonathan"),
            TempClass(1, 4.5, "dotan"),
            TempClass(1, 1.5, "dotan"),
            TempClass(1, 1.5, "danino")
        };
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Descending order iterator operator[].
     */
    SUBCASE("[]"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);

        auto begin = container.begin_descending_order();
        auto end = container.end_descending_order();
        std::vector<int> expected = {15, 7, 6, 2, 1};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(begin[i] == expected[i]);
            CHECK(begin[i] == *begin);//make sure operator* and operator[i] are the same
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Descending order iterator on empty container.
     */
    SUBCASE("Empty container"){
        MyContainer<double> container;
        auto beginD = container.begin_descending_order();
        auto endD = container.end_descending_order();
        CHECK_THROWS_WITH(*beginD, "Iterator out of range");
        CHECK_THROWS_WITH(*endD, "Iterator out of range");
;
    }

    /**
     * @brief test the Descending order iterator on container with double.
     */
    SUBCASE("double"){
        MyContainer<double> container;
        container.addElement(7.5);
        container.addElement(15.2);
        container.addElement(6.3);
        container.addElement(1.1);
        container.addElement(2.4);

        auto begin = container.begin_descending_order();
        auto end = container.end_descending_order();
        std::vector<double> expected = {15.2, 7.5, 6.3, 2.4, 1.1};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
}

/**
 * @brief Test cases for Side Cross Order Iterator.
 */
TEST_CASE("Middle Out Order"){
    /**
     * @brief test the Side Cross order iterator on the example from the github readMe page.
     */
    SUBCASE("git hub example"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);

        auto begin = container.begin_middle_out_order();
        auto end = container.end_middle_out_order();
        std::vector<int> expected = {6, 15, 1, 7, 2};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
        
    }
    /**
     * @brief test the Side Cross order iterator on container with duplicate numbers.
     */
    SUBCASE("Middle Out Order - even number of elements"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);

        auto begin = container.begin_middle_out_order();
        auto end = container.end_middle_out_order();
        std::vector<int> expected = {1, 6, 2, 15, 3, 7};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
        
    }
    /**
     * @brief test the Side Cross order iterator on container with duplicate numbers.
     */
    SUBCASE("Middle Out order - with equals number"){
        MyContainer<int>  container ;
        container.addElement(17);
        container.addElement(8);
        container.addElement(1971);

        container.addElement(28);
        container.addElement(11);
        container.addElement(1975);

        container.addElement(25);
        container.addElement(12);
        container.addElement(2003);

        container.addElement(12);
        container.addElement(8);
        container.addElement(2005);

        container.addElement(15);
        container.addElement(2);
        container.addElement(2007);
        std::vector<int> expected = {12, 25, 2003, 1975, 12, 11, 8, 28, 2005, 1971, 15, 8, 2, 17, 2007};
        auto begin = container.begin_middle_out_order();
        auto end = container.end_middle_out_order();
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
    /**
     * @brief test the Side Cross order iterator on container with negative numbers.
     */
    SUBCASE("Middle out order - with negative numbers"){
        MyContainer<int>  container ;
        container.addElement(-17);
        container.addElement(8);
        container.addElement(-1971);
        container.addElement(28);
        container.addElement(11);
        container.addElement(-1975);
        std::vector<int> expected = {28,-1971,11,8,-1975,-17};
        auto begin = container.begin_middle_out_order();
        auto end = container.end_middle_out_order();
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
    /**
     * @brief test the Side Cross order iterator on container with strings.
     */
    SUBCASE("string"){
        MyContainer<string> container;
        container.addElement("sharon");
        container.addElement("shay");
        container.addElement("ori");
        container.addElement("dotan");
        container.addElement("yonathan");
        container.addElement("danino");
        container.addElement("dotan");
        auto begin = container.begin_middle_out_order();
        auto end = container.end_middle_out_order();
        std::vector<string> expected = {"dotan", "ori", "yonathan",  "shay", "danino","sharon","dotan"};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
    /**
     * @brief test the Side Cross order iterator on container with TempClass.
     *  a comparable class i build for the test because this should work on every comparable class.
     */
    SUBCASE("TempClass"){
        MyContainer<TempClass> container;
        container.addElement(TempClass(28, 11.75, "sharon"));
        container.addElement(TempClass(15, 2.5, "shay"));
        container.addElement(TempClass(6, 3.5, "ori"));
        container.addElement(TempClass(1, 4.5, "dotan"));
        container.addElement(TempClass(2, 5.5, "yonathan"));
        container.addElement(TempClass(1, 1.5, "danino"));
        container.addElement(TempClass(1,1.5,"dotan"));

        auto begin = container.begin_middle_out_order();
        auto end = container.end_middle_out_order();
        std::vector<TempClass> expected = {
            TempClass(1, 4.5, "dotan"),
            TempClass(6, 3.5, "ori"),
            TempClass(2, 5.5, "yonathan"),
            TempClass(15, 2.5, "shay"),
            TempClass(1, 1.5, "danino"),
            TempClass(28, 11.75, "sharon"),
            TempClass(1, 1.5, "dotan")
        };
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
    /**
     * @brief test the Side Cross order iterator operator[].
     */
    SUBCASE("[]"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);

        auto begin = container.begin_middle_out_order();
        auto end = container.end_middle_out_order();

        CHECK_THROWS_WITH(begin[6],"Index out of range");
        CHECK_THROWS_WITH(end[6],"Index out of range");
        CHECK_THROWS_WITH(begin[-1],"Index out of range");
        CHECK_THROWS_WITH(end[-1],"Index out of range");

        std::vector<int> expected = {6, 15, 1, 7, 2};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(begin[i] == expected[i]);
            CHECK(begin[i] == *begin);//make sure operator* and operator[i] are the same
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
    /**
     * @brief test the Side Cross order iterator on empty container.
     */
    SUBCASE("Empty container"){
        MyContainer<double> container;
        auto beginM = container.begin_middle_out_order();
        auto endM = container.end_middle_out_order();
        CHECK_THROWS_WITH(*beginM, "Iterator out of range");
        CHECK_THROWS_WITH(*endM, "Iterator out of range");
    }

    /**
     * @brief test the Side Cross order iterator on container with double.
     */
    SUBCASE("double"){
        MyContainer<double> container;
        container.addElement(7.5);
        container.addElement(15.2);
        container.addElement(6.3);
        container.addElement(1.1);
        container.addElement(2.4);

        auto begin = container.begin_middle_out_order();
        auto end = container.end_middle_out_order();
        std::vector<double> expected = {6.3, 15.2, 1.1, 7.5, 2.4};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
}

/**
 * @brief Test cases for Order Iterator.
 */
TEST_CASE("Order"){
    /**
     * @brief Test cases for Order Iterator.
     * This iterator returns the elements in the order they were added to the container.
     */
    SUBCASE("git hub example"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);

        auto begin = container.begin_order();
        auto end = container.end_order();
        std::vector<int> expected = {7, 15, 6, 1, 2};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
        
    }

    /**
     * @brief test the Order iterator on container with duplicate numbers.
     */
    SUBCASE("in Order - with equals number"){
        MyContainer<int>  container ;
        container.addElement(17);
        container.addElement(8);
        container.addElement(1971);

        container.addElement(28);
        container.addElement(11);
        container.addElement(1975);

        container.addElement(25);
        container.addElement(12);
        container.addElement(2003);

        container.addElement(12);
        container.addElement(8);
        container.addElement(2005);

        container.addElement(15);
        container.addElement(2);
        container.addElement(2007);
        std::vector<int> expected = {17 , 8 , 1971, 28, 11, 1975, 25, 12, 2003, 12, 8, 2005, 15, 2, 2007};
        auto begin = container.begin_order();
        auto end = container.end_order();
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Order iterator on container with negative numbers.
     */
    SUBCASE("in order - with negative numbers"){
        MyContainer<int>  container ;
        container.addElement(-17);
        container.addElement(8);
        container.addElement(-1971);
        container.addElement(28);
        container.addElement(11);
        container.addElement(-1975);
        std::vector<int> expected = {-17 , 8 ,-1971, 28, 11, -1975};
        auto begin = container.begin_order();
        auto end = container.end_order();
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Order iterator on container with strings.
     */
    SUBCASE("string"){
        MyContainer<string> container;
        container.addElement("sharon");
        container.addElement("shay");
        container.addElement("ori");
        container.addElement("dotan");
        container.addElement("yonathan");
        container.addElement("danino");
        container.addElement("dotan");
        auto begin = container.begin_order();
        auto end = container.end_order();
        std::vector<string> expected = {"sharon", "shay", "ori",  "dotan", "yonathan", "danino", "dotan"};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Order iterator on container with TempClass.
     *  a comparable class i build for the test because this should work on every comparable class.
     */
    SUBCASE("TempClass"){
        MyContainer<TempClass> container;
        container.addElement(TempClass(28, 11.75, "sharon"));
        container.addElement(TempClass(15, 2.5, "shay"));
        container.addElement(TempClass(6, 3.5, "ori"));
        container.addElement(TempClass(1, 4.5, "dotan"));
        container.addElement(TempClass(2, 5.5, "yonathan"));
        container.addElement(TempClass(1, 1.5, "danino"));
        container.addElement(TempClass(1,1.5,"dotan"));

        auto begin = container.begin_order();
        auto end = container.end_order();
        std::vector<TempClass> expected = {
            TempClass(28, 11.75, "sharon"),
            TempClass(15, 2.5, "shay"),
            TempClass(6, 3.5, "ori"),
            TempClass(1, 4.5, "dotan"),
            TempClass(2, 5.5, "yonathan"),
            TempClass(1, 1.5, "danino"),
            TempClass(1, 1.5, "dotan")
        };
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Order iterator operator[].
     */
    SUBCASE("[]"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);

        auto begin = container.begin_order();
        auto end = container.end_order();

        CHECK_THROWS_WITH(begin[6],"Index out of range");
        CHECK_THROWS_WITH(end[6],"Index out of range");
        CHECK_THROWS_WITH(begin[-1],"Index out of range");
        CHECK_THROWS_WITH(end[-1],"Index out of range");

        std::vector<int> expected = {7, 15, 6, 1, 2};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(begin[i] == expected[i]);
            CHECK(begin[i] == *begin);//make sure operator* and operator[i] are the same
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Order iterator on empty container.
     */
    SUBCASE("Empty container"){
        MyContainer<double> container;
        auto beginO = container.begin_order();
        auto endO = container.end_order();
        CHECK_THROWS_WITH(*beginO, "Iterator out of range");
        CHECK_THROWS_WITH(*endO, "Iterator out of range");
    }

    /**
     * @brief test the Order iterator on container with double.
     */
    SUBCASE("double"){
        MyContainer<double> container;
        container.addElement(7.5);
        container.addElement(15.2);
        container.addElement(6.3);
        container.addElement(1.1);
        container.addElement(2.4);

        auto begin = container.begin_order();
        auto end = container.end_order();
        std::vector<double> expected = {7.5, 15.2, 6.3, 1.1, 2.4};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
}

/**
 * @brief Test cases for Reverse order iterator.
 */
TEST_CASE("Reverse Order"){
    /**
     * @brief test the Reverse order iterator on the example from the github readMe page.
     */
    SUBCASE("git hub example"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);

        auto begin = container.begin_reverse_order();
        auto end = container.end_reverse_order();
        std::vector<int> expected = {2, 1, 6, 15, 7};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
        
    }
    /**
     * @brief test the Reverse order iterator on container with duplicate numbers.
     */
    SUBCASE("reverse Order - with equals number"){
        MyContainer<int>  container ;
        container.addElement(17);
        container.addElement(8);
        container.addElement(1971);

        container.addElement(28);
        container.addElement(11);
        container.addElement(1975);

        container.addElement(25);
        container.addElement(12);
        container.addElement(2003);

        container.addElement(12);
        container.addElement(8);
        container.addElement(2005);

        container.addElement(15);
        container.addElement(2);
        container.addElement(2007);
        std::vector<int> expected = {2007,2,15,2005,8,12,2003,12,25,1975,11,28,1971,8,17};
        auto begin = container.begin_reverse_order();
        auto end = container.end_reverse_order();
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Reverse order iterator on container with negative numbers.
     */
    SUBCASE("reverse order - with negative numbers"){
        MyContainer<int>  container ;
        container.addElement(-17);
        container.addElement(8);
        container.addElement(-1971);
        container.addElement(28);
        container.addElement(11);
        container.addElement(-1975);
        std::vector<int> expected = {-1975 , 11 ,28, -1971, 8, -17};
        auto begin = container.begin_reverse_order();
        auto end = container.end_reverse_order();
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Reverse order iterator on container with strings.
     */
    SUBCASE("string"){
        MyContainer<string> container;
        container.addElement("sharon");
        container.addElement("shay");
        container.addElement("ori");
        container.addElement("dotan");
        container.addElement("yonathan");
        container.addElement("danino");
        container.addElement("dotan");
        auto begin = container.begin_reverse_order();
        auto end = container.end_reverse_order();
        std::vector<string> expected = {"dotan","danino", "yonathan", "dotan", "ori", "shay", "sharon"};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Reverse order iterator on container with TempClass.
     */
    SUBCASE("TempClass"){
        MyContainer<TempClass> container;
        container.addElement(TempClass(28, 11.75, "sharon"));
        container.addElement(TempClass(15, 2.5, "shay"));
        container.addElement(TempClass(6, 3.5, "ori"));
        container.addElement(TempClass(1, 4.5, "dotan"));
        container.addElement(TempClass(2, 5.5, "yonathan"));
        container.addElement(TempClass(1, 1.5, "danino"));
        container.addElement(TempClass(1,1.5,"dotan"));

        auto begin = container.begin_reverse_order();
        auto end = container.end_reverse_order();
        std::vector<TempClass> expected = {
            TempClass(1, 1.5, "dotan"),
            TempClass(1, 1.5, "danino"),
            TempClass(2, 5.5, "yonathan"),
            TempClass(1, 4.5, "dotan"),
            TempClass(6, 3.5, "ori"),
            TempClass(15, 2.5, "shay"),
            TempClass(28, 11.75, "sharon")
        };
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Reverse order iterator operator[].
     */
    SUBCASE("[]"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);

        auto begin = container.begin_reverse_order();
        auto end = container.end_reverse_order();
        CHECK_THROWS_WITH(begin[6],"Index out of range");
        CHECK_THROWS_WITH(end[6],"Index out of range");
        CHECK_THROWS_WITH(begin[-1],"Index out of range");
        CHECK_THROWS_WITH(end[-1],"Index out of range");
        std::vector<int> expected = {2, 1, 6, 15, 7};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(begin[i] == expected[i]);
            CHECK(begin[i] == *begin);//make sure operator* and operator[i] are the same
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }

    /**
     * @brief test the Reverse order iterator on empty container.
     */
    SUBCASE("Empty container"){
        MyContainer<double> container;
        auto beginR = container.begin_reverse_order();
        auto endR = container.end_reverse_order();
        CHECK_THROWS_WITH(*beginR, "Iterator out of range");
        CHECK_THROWS_WITH(*endR, "Iterator out of range");
    }
    /**
     * @brief test the Reverse order iterator on container with double.
     */
    SUBCASE("double"){
        MyContainer<double> container;
        container.addElement(7.5);
        container.addElement(15.2);
        container.addElement(6.3);
        container.addElement(1.1);
        container.addElement(2.4);

        auto begin = container.begin_reverse_order();
        auto end = container.end_reverse_order();
        std::vector<double> expected = {2.4, 1.1, 6.3, 15.2, 7.5};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
}
/**
 * @brief Test cases for Side Cross Order Iterator.
 */
TEST_CASE("Side Cross Order"){
    /**
     * @brief test the Side Cross order iterator on the example from the github readMe page.
     */
    SUBCASE("git hub example"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);

        auto begin = container.begin_side_cross_order();
        auto end = container.end_side_cross_order();
        std::vector<int> expected = {1, 15, 2, 7, 6};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
        
    }
    /**
     * @brief test the Side Cross order iterator on container with duplicate numbers.
     */
    SUBCASE("side cross Order - with equals number"){
        MyContainer<int>  container ;
        container.addElement(17);
        container.addElement(8);
        container.addElement(1971);

        container.addElement(28);
        container.addElement(11);
        container.addElement(1975);

        container.addElement(25);
        container.addElement(12);
        container.addElement(2003);

        container.addElement(12);
        container.addElement(8);
        container.addElement(2005);

        container.addElement(15);
        container.addElement(2);
        container.addElement(2007);
        std::vector<int> expected = {2,2007,8,2005,8,2003,11,1975,12,1971,12,28,15,25,17};
        auto begin = container.begin_side_cross_order();
        auto end = container.end_side_cross_order();
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
    /**
     * @brief test the Side Cross order iterator on container with negative numbers.
     */
    SUBCASE("side cross order - with negative numbers"){
        MyContainer<int>  container ;
        container.addElement(-17);
        container.addElement(8);
        container.addElement(-1971);
        container.addElement(28);
        container.addElement(11);
        container.addElement(-1975);
        std::vector<int> expected = {-1975, 28, -1971, 11, -17, 8};
        auto begin = container.begin_side_cross_order();
        auto end = container.end_side_cross_order();
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
    /**
     * @brief test the Side Cross order iterator on container with strings.
     */
    SUBCASE("string"){
        MyContainer<string> container;
        container.addElement("sharon");
        container.addElement("shay");
        container.addElement("ori");
        container.addElement("dotan");
        container.addElement("yonathan");
        container.addElement("danino");
        container.addElement("dotan");
        auto begin = container.begin_side_cross_order();
        auto end = container.end_side_cross_order();
        std::vector<string> expected = {"danino", "yonathan", "dotan", "shay", "dotan", "sharon", "ori"};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
    /**
     * @brief test the Side Cross order iterator on container with TempClass.
     */
    SUBCASE("TempClass"){
        MyContainer<TempClass> container;
        container.addElement(TempClass(28, 11.75, "sharon"));
        container.addElement(TempClass(15, 2.5, "shay"));
        container.addElement(TempClass(6, 3.5, "ori"));
        container.addElement(TempClass(1, 4.5, "dotan"));
        container.addElement(TempClass(2, 5.5, "yonathan"));
        container.addElement(TempClass(1, 1.5, "danino"));
        container.addElement(TempClass(1,1.5,"dotan"));

        auto begin = container.begin_side_cross_order();
        auto end = container.end_side_cross_order();
        std::vector<TempClass> expected = {
            TempClass(1, 1.5, "danino"),
            TempClass(28, 11.75, "sharon"),
            TempClass(1, 1.5, "dotan"),
            TempClass(15, 2.5, "shay"),
            TempClass(1, 4.5, "dotan"),
            TempClass(6, 3.5, "ori"),
            TempClass(2, 5.5, "yonathan")
        };
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
    /**
     * @brief test the Side Cross order iterator operator[].
     */
    SUBCASE("[]"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);

        auto begin = container.begin_side_cross_order();
        auto end = container.end_side_cross_order();

        CHECK_THROWS_WITH(begin[6],"Index out of range");
        CHECK_THROWS_WITH(end[6],"Index out of range");
        CHECK_THROWS_WITH(begin[-1],"Index out of range");
        CHECK_THROWS_WITH(end[-1],"Index out of range");
        
        std::vector<int> expected = {1, 15, 2, 7, 6};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(begin[i] == expected[i]);
            CHECK(begin[i] == *begin);//make sure operator* and operator[i] are the same
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
    /**
     * @brief test the Side Cross order iterator on empty container.
     */
    SUBCASE("Empty container"){
        MyContainer<double> container;
        auto beginS = container.begin_side_cross_order(); 
        auto endS = container.end_side_cross_order();
        CHECK_THROWS_WITH(*beginS, "Iterator out of range");
        CHECK_THROWS_WITH(*endS, "Iterator out of range");
    }

    /**
     * @brief test the Side Cross order iterator on container with double.
     */
    SUBCASE("double"){
        MyContainer<double> container;
        container.addElement(7.5);
        container.addElement(15.2);
        container.addElement(6.3);
        container.addElement(1.1);
        container.addElement(2.4);

        auto begin = container.begin_side_cross_order();
        auto end = container.end_side_cross_order();
        std::vector<double> expected = {1.1, 15.2, 2.4, 7.5, 6.3};
        size_t i=0;
        for (i=0; begin !=end;++begin, i++)
        {
            CHECK(*begin == expected[i]);
        }
        CHECK(i == expected.size());//make sure we iterated through all elements
    }
}