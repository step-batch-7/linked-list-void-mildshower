#include <stdio.h>
#include <assert.h>
#include "../linkedlist.h"

void test_create_list(void)
{
  printf("\n\nTesting create_list\n\n");

  printf("\tShould create an empty list\n");
  List_ptr list = create_list();
  assert(list->first==NULL);
  assert(list->last==NULL);
  assert(list->length == 0);
  printf("\t\t--passed\n\n");
}

void test_create_node(void)
{
  printf("\n\nTesting create_node\n\n");

  printf("\tShould create a node with the given element\n");
  int *number = malloc(sizeof(int));
  *number = 0;
  Node_ptr node = create_node(number);
  assert(*(int *)node->element==0);
  assert(node->next == NULL);
  printf("\t\t--passed\n\n");
}

int main(void){
  test_create_list();
  test_create_node();

  return 0;
}