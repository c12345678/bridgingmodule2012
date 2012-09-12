#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *progname;	// File visible program name string. Set in main() from argv[0]

static void usage(void)
{
    fprintf(stderr, "Usage: %s ...\n", progname);
    exit(1);
}

/*
 * The linked list node
 */
struct node {
  int val;		// The node's data. Could be any type or types
  struct node *next;	// A pointer to the successor node in the list
  			// or NULL if at the end of the list
};

/*
 * The list head. Note that in this implemenation, because this is file global, 
 * there can only be one list in existance. See the C++ version for a better
 * way to do this, supporting multiple independent linked lists
 */
struct node head = { -1, NULL };

/*
 * Output each linked list value
 */
void print(void)
{
  struct node *nptr = head.next;	// A variable that holds a pointer to any list node
  					// Initially points to the first node following the head
  					// i.e. the first "real" node of the list

  // Loop over the list nodes until we reach the end, printing each value
  while (nptr != NULL) {
    printf("%6d", nptr->val);
    nptr = nptr->next;			// Move on to the successor node
  }
  printf("\n");
}

// Create a list node and initialise its values
struct node *create(int val)
{
  struct node * nptr = (struct node *)malloc(sizeof(struct node));
  nptr->val = val;
  nptr->next = NULL;

  return nptr;
}

// Wrapper function to free
void destroy(struct node *nptr)
{
  free(nptr);
}

// Insert a node after the specified previous node
struct node *insert(int val, struct node *prev)
{
  struct node *nptr = create(val);
  // Make new node's next pointer point to previous node's next pointer
  nptr->next = prev->next;
  prev->next = nptr;

  return nptr;
}

// Add a node to the end of the list
struct node *append(int val)
{
  struct node *nptr = &head;

  // Find the end of the list by looping over all nodes until the successor
  // is NULL, i.e. we are at the end
  while (nptr->next != NULL) {
    nptr = nptr->next;
  }
  return insert(val, nptr);
}

// Add a node to the start of the list
struct node *prepend(int val)
{
  // Finding the start of the list is trivial. It's the head and it will be
  // previous pointer to our new node.
  struct node *nptr = &head;

  return insert(val, nptr);
}

// Add a node in sorted (ascending) order
struct node *insertInOrder(int val)
{
  struct node *prev = &head;
  struct node *nptr = head.next;

  // Here we maintain two pointers in sync. One points to the node we are
  // examining and the  other points to our predecessor node.
  while (nptr != NULL && nptr->val < val) {
    prev = nptr;
    nptr = nptr->next;
  }
  return insert(val, prev);
}

// Find the first occurence of the specified value
struct node * find(int val)
{
  struct node *nptr = head.next;

  // Loop over all the nodes, testing for the sought value
  while (nptr != NULL && nptr->val != val) {
    nptr = nptr->next;
  }

  // We can get either because we matched the value or we hit the end of
  // the list. Or both. Therefore we test the value again to see which.
  if (nptr->val == val) {
    return nptr;
  }
  return NULL;
}

// Remove a node with the specified value (if it exists)
int delete(int val)
{
  struct node *prev = &head;
  struct node *nptr = head.next;

  // This is like find, except as with insertInOrder, we maintain a 
  // predecessor pointer so we can repair list when removing a node in
  // the middle of two others
  while (nptr != NULL && nptr->val != val) {
    prev = nptr;
    nptr = nptr->next;
  }
  if (nptr->val == val) {
    prev->next = nptr->next;
    destroy(nptr);
    return val;
  }
  return -1;
}

// Handy macro for counting the number of elements in a statically
// initialised array, independent of the array element type
#define SIZE(a)	(sizeof(a) / sizeof(a[0]))

int main(int argc, char *argv[])
{
  char inString[10];
  progname = argv[0];
  int i;

  // Put some numbers into our list to start off
  int members[] = {1, 2, 5, 7, 7, 8, 9, 10};
  int size = SIZE(members);
  for (i = 0; i < size; i++) {
    insertInOrder(members[i]);
  }
  print();

  // Prompt the user for values until the numer "0"
  while (1) {
    printf("> ");
    fgets(inString, sizeof(inString), stdin);
    int val = atoi(inString);
    if (val == 0) {
      break;
    }
    insertInOrder(val);
    print();
  }

  return 0;
}
