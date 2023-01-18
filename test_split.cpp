/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <cstddef>
using namespace std;

int main(int argc, char* argv[])
{
    Node* odds = NULL;
    Node* evens = NULL;
    // odds->value = NULL;
    // evens->value = NULL;
    // Node* temp;
    // temp->value = NULL;
    Node* in = new Node(1, new Node(2, new Node(3, new Node(4, NULL))));

    split(in, odds, evens);

    // printing test to see if the values are correct

    cout << "Odd List" << endl;
    Node* curr = odds;
    while (curr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;

    cout << "Even List" << endl;
    curr = evens;
    while (curr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
    

}
