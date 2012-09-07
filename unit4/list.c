#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *progname;

static void usage(void)
{
    fprintf(stderr, "Usage: %s ...\n", progname);
    exit(1);
}

/*
 * The linked list node
 */
struct node {
  int val;
  struct node *next;
};

/*
 * The list head
 */
struct node head = { -1, NULL };

/*
 * Output each linked list value
 */
void print(void)
{
  struct node *nptr = head.next;

  while (nptr != NULL) {
    printf("%6d", nptr->val);
    nptr = nptr->next;
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

  while (nptr->next != NULL) {
    nptr = nptr->next;
  }
  return insert(val, nptr);
}

// Add a node to the start of the list
struct node *prepend(int val)
{
  struct node *nptr = &head;

  return insert(val, nptr);
}

// Add a node in sorted (ascending) order
struct node *insertInOrder(int val)
{
  struct node *prev = &head;
  struct node *nptr = head.next;

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

  while (nptr != NULL && nptr->val != val) {
    nptr = nptr->next;
  }

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

#define SIZE(a)	(sizeof(a) / sizeof(a[0]))

int main(int argc, char *argv[])
{
  char inString[10];
  progname = argv[0];
  int i;

  int members[] = {1, 2, 5, 7, 7, 8, 9, 10, 0};
  int size = SIZE(members);
  for (i = 0; i < size; i++) {
  }

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
