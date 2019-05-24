#include <gtest/gtest.h>
#include "SimplyLinkedList.hpp"

#include <iostream>

using namespace std;
using ::testing::InitGoogleTest;
using ::testing::Test;

TEST(TestSimplyLinkedList, test_node_null_contor)
{
    Node<float> node = Node<float>();

    ASSERT_EQ(node.next, nullptr);
    ASSERT_EQ(node.entry, 0);
}

TEST(TestSimplyLinkedList, test_node_contor)
{
    Node<float> node_0 = Node<float>();
    Node<float> node = Node<float>(1.f, &node_0);

    ASSERT_EQ(node.next, &node_0);
    ASSERT_EQ(node.entry, 1.f);
}

TEST(TestSimplyLinkedList, test_list_contor)
{
    SimplyLinkedList<float> slist = SimplyLinkedList<float>();

    ASSERT_EQ(slist.size(), 0);
}

int main()
{
    InitGoogleTest();

    return RUN_ALL_TESTS();
}