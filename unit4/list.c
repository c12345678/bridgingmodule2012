#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *progname;

static void usage(void)
{
    fprintf(stderr, "Usage: %s ...\n", progname);
    exit(1);
}

struct node {
  int val;
  struct node *next;
};

struct node head = { -1, NULL };

void print(void)
{
  struct node *nptr = head.next;

  while (nptr != NULL) {
    printf("%6d", nptr->val);
    nptr = nptr->next;
  }
  printf("\n");
}

// Create
struct node *create(int val)
{
  struct node * nptr = (struct node *)malloc(sizeof(struct node));
  nptr->val = val;
  nptr->next = NULL;

  return nptr;
}

void destroy(struct node *nptr)
{
  free(nptr);
}

// Insert
struct node *insert(int val, struct node *prev)
{
  struct node *nptr = create(val);
  nptr->next = prev->next;
  prev->next = nptr;

  return nptr;
}

// Append
struct node *append(int val)
{
  struct node *nptr = &head;

  while (nptr->next != NULL) {
    nptr = nptr->next;
  }
  return insert(val, nptr);
}

struct node *prepend(int val)
{
  struct node *nptr = &head;

  return insert(val, nptr);
}

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

// Search
struct node *find(int val)
{
}

// Remove
void delete(int val)
{
}

int main(int argc, char *argv[])
{
  char inString[10];
  progname = argv[0];

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
