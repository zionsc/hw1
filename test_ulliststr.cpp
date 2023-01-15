#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr x;
    // test 1 --> push_back
    x.push_back("5");
    x.push_back("0");
    x.push_back("3"); // 5 0 3

    // test 2 --> push_front
    x.push_front("4");
    x.push_front("1");
    x.push_front("9"); // 9 1 4 5 0 3

    // test 3 --> pop_back
    x.pop_back();
    x.pop_back(); // 9 1 4 5

    // test 4 --> pop_front
    x.pop_front();
    x.pop_front(); // 4 5

    // test 5 --> back
    cout << "back! " << x.back() << endl; // 5

    // test 6 --> front
    cout << "front! " << x.front() << endl; // 4

    // test 7 --> getValatLoc
    cout << "get value at index 0 " << *(x.getValAtLoc("0")) << endl; // 4



    UlListStr y; // various edge cases
    // test 1 --> back and front same if only one number
    y.push_back("3");

    cout << "front! " << y.front(); << endl; // 3
    cout << "back! " << y.back(); << endl; // 3

    



}
