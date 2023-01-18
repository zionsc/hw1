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

size_t ULListStr::size()
{
  return size_++; // starts at 0
}

// WRITE YOUR CODE HERE

// push_back, push_front, pop_back, pop_front, back, front and getValAtLoc in ulliststr.cpp.

void ULListStr::push_back(const std::string& val)
{
  if (size_==0) {
    Item* temp = new Item; // head and tail both point 
    head_ = temp;
    tail_ = temp;
    temp = head_;// question about this --> necessary or no
    temp->val[temp->last] = val;
    temp->last++;
    size_++;
  }
  
  else if (tail_->last == 10) { // set 10 max
    Item* temp = new Item;
    temp->val[temp->last] = val;
    temp->last++;
    temp->prev = tail_;
    tail_->next = temp;
    tail_ = tail_->next;
    size_++;
    tail_->next = NULL;
  }

  else {
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
  }
}

void ULListStr::push_front(const std::string& val) 
{
  if (size_==0) {
    Item* temp = new Item;
    head_ = temp;
    tail_ = temp;
    temp = head_; // question about this --> necessary or no
    temp->first = 10;
    temp->last = 10;
    temp->first--;
    temp->val[temp->first] = val; // after subbing
    size_++;
  }

  else if (head_->first==0) {
    Item* temp = new Item;
    temp->first = 10;
    temp->last = 10;
    temp->first--;
    temp->val[temp->first] = val; // after subbing
    temp->next = head_; // set next val to head
    head_->prev = temp; // now that head is gone, set head's prev to the new temp
    head_ = head_->prev; // set that temp val to new head
    head_->prev = NULL;
  }

  else {
    head_->first--;
    head_->val[head_->first] = val;
    size_++;
  }
}

void ULListStr::pop_back()
{
  if (empty()) {
    return;
  }

  else if (tail_->last == 1 && tail_->first == 0) { // if only one val --> change tail pointer itself
    size_--;
    tail_ = tail_->prev;
  }

  else { // does not create empty list when popped back
    size_--;
    tail_->last--;
  }
}

void ULListStr::pop_front()
{
  if (empty()) {
    return;
  }

  else if (head_->first == 9 && head_->last == 10) { // if only one val --> change head pointer itself
    size_--;
    head_ = head_->next;
  }

  else { // does not create empty list when popped front
    size_--;
    head_->first++;
  }
}

std::string const & ULListStr::back() const
{
  Item* temp = tail_;
  --temp->last;
  return temp->val[temp->last];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

/*
return a pointer to the i-th value in the entire list (not just in a
single Item’s array) and is used in several other member functions.
If a non-existent location provided to getValAtLoc should cause it to return NULL.
*/

std::string* ULListStr::getValAtLoc(size_t loc) const 
// return an address to allow pass by reference to that addrespoint -> may want to change that point
{
  Item* temp = head_;
  int locUse = int(loc);
  while (locUse != 0) {
    int start = (int)(temp->first);
    int end = (int)(temp->last);
    int x = end-start;
    if (locUse >= x) {
      temp = temp->next;
      locUse -= x;
    }
    else {
      temp->first++;
      locUse--;
    }
  }
  return &(temp->val[temp->first]);
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
