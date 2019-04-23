#include <iostream>

#include "ContiguousList.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    List<int> myList = List<int>();

    cout << "size: " << myList.size() << endl;

    return 0;
}