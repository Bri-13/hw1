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
#include <cstddef>

// prototype for a helper function
bool isEven(const Node* input);

void split(Node*& in, Node*& odds, Node*& evens)
{
  // check if original list is empty (base case)
  if(in == nullptr){
    return;
  }

  // check if value of temp is even and split accordingly (recursive case)
  Node* temp = in;
  in = in->next;
  temp->next = nullptr;
  if(isEven(temp)){
    // add temp to the front of evens
    temp->next = evens;
    evens = temp;
  }
  else{
    // add temp to front of odds
    temp->next = odds;
    odds = temp;
  }
  split(in, odds, evens);
}

// helper function to check if the value is even
bool isEven(const Node* input) {
  if((input->value % 2) == 0){
    return true;
  }
  return false;
}