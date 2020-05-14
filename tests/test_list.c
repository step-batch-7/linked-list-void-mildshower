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

void test_add_to_list(void)
{
  printf("\n\nTesting add_to_list\n\n");

  List_ptr list = create_list();
  int *number = malloc(sizeof(int));
  *number = 0;
  printf("\tShould add new number at End when list is empty\n");
  assert(add_to_list(list, number));
  assert(*(int *)list->last->element == 0);
  assert(*(int *)list->first->element == 0);
  assert(list->length == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould add new number at End when list has elements\n");
  assert(add_to_list(list, number));
  assert(*(int *)list->last->element == 0);
  assert(list->length == 2);
  printf("\t\t--passed\n\n");
}

void test_add_to_start(void)
{
  printf("\n\nTesting add_to_start\n\n");

  List_ptr list = create_list();
  int *number = malloc(sizeof(int));
  *number = 0;
  printf("\tShould add new number at Start when list is empty\n");
  assert(add_to_start(list, number));
  assert(*(int *)list->first->element == 0);
  assert(*(int *)list->last->element == 0);
  assert(list->length == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould add new number at Start when list has elements\n");
  assert(add_to_start(list, number));
  assert(*(int *)list->first->element == 0);
  assert(*(int *)list->last->element == 0);
  assert(list->length == 2);
  printf("\t\t--passed\n\n");
}

int main(void){
  test_create_list();
  test_create_node();
  test_add_to_list();
  test_add_to_start();

  return 0;
}