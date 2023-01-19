/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  if (!in) { // check if original list does not exist/nullptr --> return
    return;
  }
  
  else if (in->value % 2 == 0) {
    evens = in;
    split(in->next, odds, evens->next);
  }

  else if (in->value <= 0) { // negative numbers + 0
    split(in->next, odds, evens);
  }

  else if (in->value % 2 != 0) {
    odds = in;
    split(in->next, odds->next, evens);
  }

  if (!in->next) {
    if (!evens || !odds) {
      return;
    }
    if (evens->value % 2 != 0) {
      evens = NULL;
    }
    if (odds->value % 2 == 0) {
      odds = NULL;
    }
  }
}

/* If you needed a helper function, write it here */
