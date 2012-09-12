/*
 * C++ Implementation of a singly-linked list
 *
 * Compile with:
 *   g++ -o list list.cpp
 */
#include <iostream>
#include <iomanip>

using namespace std;

// The list node
class ListNode {
  int val;
  ListNode *next;

public:
  ListNode(void) { this->val = -1; next = 0; }
  ListNode(const int val) { this->val = val; next = 0; }
  ListNode(const int val, ListNode *next) { this->val = val; this->next = next; }
  int getVal(void) { return val; }
  bool hasNext(void) { return next != 0; }
  ListNode * getNext(void) { return next; }
  ListNode * setNext(ListNode *next) { this->next = next; return next; }
  ~ListNode() { }
};

// The list itself
class LinkedList {
  ListNode head;

public:
  ListNode *append(const int val);
  ListNode *prepend(const int val);
  ListNode *insert(const int val);
  ListNode *find(const int val);
  int remove(const int val);
  void print(void);
};

// Add to the end of the list
ListNode * LinkedList::append(const int val)
{
  ListNode *node = &head;

  while (node->hasNext()) {
    node = node->getNext();
  }
  return node->setNext(new ListNode(val));
}

// Insert at the beginning of the list
ListNode * LinkedList::prepend(const int val)
{
  return head.setNext(new ListNode(val, head.getNext()));
}

// Insert in sorted order (ascending)
ListNode * LinkedList::insert(const int val)
{
  ListNode *node = head.getNext();
  ListNode *prev = &head;

  while (node != 0 && node->getVal() < val) {
    prev = node;
    node = node->getNext();
  }
  return prev->setNext(new ListNode(val, prev->getNext()));
}

// Look for a node having the specified value
ListNode * LinkedList::find(const int val)
{
  ListNode *node = head.getNext();

  while (node != 0 && node->getVal() != val) {
    node = node->getNext();
  }
  if (node->getVal() == val) {
    return node;
  }
  return 0;
}

// Remove the first node having the specified value (if present)
int LinkedList::remove(const int val)
{
  ListNode *node = head.getNext();
  ListNode *prev = &head;

  while (node != 0 && node->getVal() != val) {
    prev = node;
    node = node->getNext();
  }
  if (node->getVal() == val) {
    prev->setNext(node->getNext());
    delete node;
    return val;
  }
  return -1;
}

// Show the contents of the list
void LinkedList::print(void)
{
  ListNode *node = head.getNext();

  while (node != 0) {
    cout << setw(6) << node->getVal();
    node = node->getNext();
  }
  cout << endl;
}

int main(int argc, char *argv[])
{
  LinkedList list;

  // Add the numbers 10 to 1 in sorted order
  for (int n = 10; n >= 1; n--) {
    list.insert(n);
  }
  // Remove element 5 from the list
  list.remove(5);
  // Display the resulting list
  list.print();
}
