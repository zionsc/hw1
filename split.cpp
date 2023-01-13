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

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  if (!in) { // check if original list does not exist --> return
    return;
  }
  
  if (in->val % 2 != 0) {
    if (odds) {
      odds->next = split(in->next, odds->next, evens);
    }
    else { // if !odds
      odds = in;
    }
  }
  else { // if odd --> % 2 == 0
    if (evens) {
      evens->next = split(in->next, odds, evens->next);
    }
    else {
      evens = in;
    }
  }

  in->next = NULL;
  in = NULL;
  return in;

}

/* If you needed a helper function, write it here */
