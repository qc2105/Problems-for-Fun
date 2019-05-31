#include <gtest/gtest.h>
#include <iostream>

#include "DoublyLinkedList.hpp"

using namespace std;
using ::testing::InitGoogleTest;
using ::testing::Test;

TEST(testDoublyLinkedList, testNodeContor)
{
    Node<float> nod = Node<float>();

    ASSERT_EQ(nod.entry, 0.f);
    ASSERT_EQ(nod.next, nullptr);
    ASSERT_EQ(nod.back, nullptr);

    Node<float> nod2 = Node<float>(2.f, &nod, &nod);

    ASSERT_EQ(nod2.entry, 2.f);
    ASSERT_EQ(nod2.next, &nod);
    ASSERT_EQ(nod2.back, &nod);
}

int main()
{
    InitGoogleTest();

    return RUN_ALL_TESTS();
}