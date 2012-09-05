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

struct node *head = NULL;

// Create
struct node *create(int val)
{
  struct node *nptr = (struct node *)malloc(sizeof(struct node));
  nptr->val = val;
  nptr->next = NULL;

  return nptr;
}

void destroy(struct node *node)
{
  node->val = -1;
  node->next = NULL;
  free(node);
}

// Insert
struct node *insert(int val, struct node *prev)
{
  struct node *nptr = create(val);
  nptr->next = prev->next;
  prev->next = nptr;

  return nptr;
}

// Search
struct node *search(int val)
{
}

// Remove
void delete(int val)
{
}

int main(int argc, char *argv[])
{
  progname = argv[0];
  if (argc < 3) {
    usage();
  }

  struct node *nptr = insert(128, head);
  destroy(nptr);

  return 0;
}
