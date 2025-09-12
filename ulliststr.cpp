#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
/**
* Adds a new value to the back of the list
*   - MUST RUN in O(1)
*/
void ULListStr::push_back(const std::string& val){
  if((tail_ != NULL) && tail_->last != ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last += 1;
  }
  else{
    Item* newNode = new Item();
    newNode->val[0] = val;
    newNode->first = 0;
    newNode->last = 1;
    // check if the list is empty
    if(tail_ == NULL){
      head_ = newNode;
    }
    else{
      tail_->next = newNode;
      newNode->prev = tail_;
    }
    tail_ = newNode; 
  }
  size_++;
}

/**
* Removes a value from the back of the list
*   - MUST RUN in O(1)
*/
void ULListStr::pop_back(){
  // check if list is empty
  if(tail_ == NULL){
    return;
  }
  
  // delete last node if there was only one element
  if(tail_->first == (tail_->last - 1)){
    if(tail_ == head_){
      tail_ = NULL;
      delete head_;
      head_ = NULL;
    }
    else{
      Item* temp = tail_;
      tail_ = tail_->prev;
      tail_->next = NULL;
      delete temp;
    }
  }
  else{
    // delete last element
    tail_->last -= 1;
  }
  size_--;  
}

/**
* Adds a new value to the front of the list.
* If there is room before the 'first' value in
* the head node add it there, otherwise, 
* allocate a new head node.
*   - MUST RUN in O(1)
*/
void ULListStr::push_front(const std::string& val){
  if((head_ != NULL) && head_->first > 0){
    head_->first -= 1;
    head_->val[head_->first] = val;
  }
  else{
    Item* newNode = new Item();
    newNode->val[ARRSIZE - 1] = val;
    newNode->first = ARRSIZE-1;
    newNode->last = ARRSIZE;
    // check if the list is empty
    if(head_ == NULL){
      tail_ = newNode;
    }
    else{
      newNode->next = head_;
      head_->prev = newNode;
    }
    head_ = newNode;
  }
  size_++;
}

/**
* Removes a value from the front of the list
*   - MUST RUN in O(1)
*/
void ULListStr::pop_front(){
  // check if list is empty
  if(head_ == NULL){
    return;
  }

  // delete the first node if there was only one element
  if(head_->first+1 == (head_->last)){
    Item* temp = head_;
    head_ = head_->next;
    delete temp;
    if(head_ == NULL){
      tail_ = NULL;
    }
  }
  else{
    head_->first += 1;
  }
  size_--;
}

/**
* Returns a const reference to the back element
*   - MUST RUN in O(1)
*/
std::string const & ULListStr::back() const{
  std::string const& lastE = tail_->val[tail_->last-1];
  return lastE;
}

/**
* Returns a const reference to the front element
*   - MUST RUN in O(1)
*/
std::string const & ULListStr::front() const{
  std::string const& firstE = head_->val[head_->first];
  return firstE;
}

/** 
* Returns a pointer to the item at index, loc,
*  if loc is valid and NULL otherwise
*   - MUST RUN in O(n) 
*/
std::string* ULListStr::getValAtLoc(size_t loc) const{
  // check if loc is valid
  if(loc >= size_ || loc < 0){
    return NULL;
  }
  
  // walk through val and list up to loc
  Item* temp = head_;
  std::string* curr = temp->val + temp->first;
  //size_t count = temp->first;
  for(size_t i=0; i<loc; i++){
    if(curr+1 < temp->val + temp->last){
      curr++;
    }
    else{
      temp = temp->next;
      curr = temp->val;
    }
  }
  return curr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
