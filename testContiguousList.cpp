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

int main(int argc, char *argv[])
{
    InitGoogleTest();

    RUN_ALL_TESTS();

    return 0;
}