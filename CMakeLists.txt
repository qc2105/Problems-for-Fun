cmake_minimum_required(VERSION 3.1.0)
project("Problems for Fun")

include_directories(src/cpp/lists)

add_executable(single_linked_list src/cpp/lists/single_linked_list.cpp)
target_link_libraries(single_linked_list)

add_executable(TheSuperMarketQueue src/cpp/TheSuperMarketQueue.cpp)

add_executable(testContiguousList src/cpp/lists/tests/testContiguousList.cpp)
target_link_libraries(testContiguousList gtest pthread)

add_executable(testSimplyLinkedList src/cpp/lists/tests/testSimplyLinkedList.cpp)
target_link_libraries(testSimplyLinkedList gtest pthread)