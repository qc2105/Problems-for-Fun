#include <iostream>
#include <gtest/gtest.h>

using ::testing::InitGoogleTest;
using ::testing::Test;

#include "ContiguousList.hpp"

using namespace std;

TEST(TestContiguousList, test_size)
{
    List<int> myList = List<int>();
    ASSERT_EQ(myList.size(), 0);
}

TEST(TestContiguousList, test_function_full)
{
    List<int> myList = List<int>();
    ASSERT_FALSE(myList.full());
}

TEST(TestContiguousList, test_insert_retrieve)
{
    List<int> myList = List<int>();
    ASSERT_EQ(myList.insert(0, 5), success);
    ASSERT_EQ(myList.size(), 1);
    int x, y;
    myList.retrieve(0, x);
    myList.insert(1, 6);
    ASSERT_EQ(x, 5);
    myList.retrieve(1, y);
    ASSERT_EQ(y, 6);
}

int main(int argc, char *argv[])
{
    InitGoogleTest();

    return RUN_ALL_TESTS();
}