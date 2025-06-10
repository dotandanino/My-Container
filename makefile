#dotandanino@gmail.com
CXX=clang++
CXXFLAGS=-std=c++2a -g -Wall -Wextra
TARGET=Main
HEADERS=include/MyContainer.hpp include/tempClass.hpp include/AcsendingOrderIterator.hpp include/DescendingOrderIterator.hpp include/MiddleOutOrderIterator.hpp include/OrderIterator.hpp include/ReverseOrderIterator.hpp include/sideCrossOrderIterator.hpp

TEST_TARGET=test_run
TEST_SRCS=srcs/test.cpp srcs/tempClass.cpp
TEST_OBJ=srcs/test.o srcs/tempClass.o
all: $(TARGET) $(TEST_TARGET)


$(TARGET): $(OBJS) srcs/Demo.o $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) srcs/Demo.o
	./Main

$(TEST_TARGET): $(TEST_OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

valgrind: $(TARGET) $(TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)


clean:
	rm -f $(TARGET) $(TEST_TARGET) *.o  srcs/Demo.o $(OBJS) $(TEST_OBJ)

.PHONY: all clean
