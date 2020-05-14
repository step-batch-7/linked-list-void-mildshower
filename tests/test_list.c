#include <stdio.h>
#include <assert.h>
#include "../linkedlist.h"

Element increment_number_element(Element number)
{
  Element incremented_number = malloc(sizeof(int));
  *(int *)incremented_number = *(int *)number + 1;
  return incremented_number;
}

void test_create_list(void)
{
  printf("\n\nTesting create_list\n\n");

  printf("\tShould create an empty list\n");
  List_ptr list = create_list();
  assert(list->first == NULL);
  assert(list->last == NULL);
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
  assert(*(int *)node->element == 0);
  assert(node->next == NULL);
  printf("\t\t--passed\n\n");
}

void test_get_node(void)
{
  printf("\n\nTesting get_node\n\n");

  List_ptr list = create_list();
  printf("\tShould give the wanted node\n");
  int *number = malloc(sizeof(int));
  *number = 0;
  assert(add_to_list(list, number));
  assert(*(int *)get_node(list, 0)->element == 0);
  printf("\t\t--passed\n\n");

  printf("\tShould give NULL when invalid position is given\n");
  assert(get_node(list, 10) == NULL);
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

void test_insert_at(void)
{
  printf("\n\nTesting insert_at\n\n");

  List_ptr list = create_list();
  int number[] = {0, 1, 2, 3, 4};
  printf("\tShould add new number at the given valid position for empty list\n");
  assert(insert_at(list, number, 0));
  assert(*(int *)list->first->element == 0);
  assert(*(int *)list->last->element == 0);
  assert(list->length == 1);
  printf("\t\t--passed\n\n");

  add_to_list(list, number + 2);
  printf("\tShould add new number at middle\n");
  assert(insert_at(list, number + 1, 1));
  assert(*(int *)list->first->element == 0);
  assert(*(int *)list->last->element == 2);
  assert(list->length == 3);
  printf("\t\t--passed\n\n");

  printf("\tShould not add new number a position is given that exceeds allowed limit\n");
  assert(!insert_at(list, number, 10));
  assert(*(int *)list->first->element == 0);
  assert(*(int *)list->last->element == 2);
  assert(list->length == 3);
  printf("\t\t--passed\n\n");

  printf("\tShould not add new number a negative position is given\n");
  assert(!insert_at(list, 0, 10));
  assert(*(int *)list->first->element == 0);
  assert(*(int *)list->last->element == 2);
  assert(list->length == 3);
  printf("\t\t--passed\n\n");

  printf("\tShould add new number at last when position is given for last\n");
  assert(insert_at(list, number + 3, 3));
  assert(*(int *)list->first->element == 0);
  assert(*(int *)list->last->element == 3);
  assert(list->length == 4);
  printf("\t\t--passed\n\n");

  printf("\tShould add new number at begining when 0 is given as position\n");
  assert(insert_at(list, number + 4, 0));
  assert(*(int *)list->first->element == 4);
  assert(*(int *)list->last->element == 3);
  assert(list->length == 5);
  printf("\t\t--passed\n\n");
}

void test_reverse(void)
{
  printf("\n\nTesting reverse\n\n");

  List_ptr list = create_list();
  printf("\tShould produce empty list when empty list is reversed\n");
  List_ptr reversed_list_1 = reverse(list);
  assert(reversed_list_1->length == 0);
  assert(reversed_list_1->first == NULL);
  assert(reversed_list_1->last == NULL);
  printf("\t\t--passed\n\n");

  printf("\tShould reverse list with elements\n");
  int numbers[] = {0, 1};
  add_to_list(list, numbers);
  add_to_list(list, numbers + 1);
  List_ptr reversed_list_2 = reverse(list);
  assert(reversed_list_2->length == 2);
  assert(*(int *)reversed_list_2->first->element == 1);
  assert(*(int *)reversed_list_2->last->element == 0);
  printf("\t\t--passed\n\n");
}

void test_map(void)
{
  printf("\n\nTesting map\n\n");

  List_ptr list = create_list();
  printf("\tShould produce empty list when empty list is mapped\n");
  List_ptr mapped_list_1 = map(list, &increment_number_element);
  assert(mapped_list_1->length == 0);
  assert(mapped_list_1->first == NULL);
  assert(mapped_list_1->last == NULL);
  printf("\t\t--passed\n\n");

  printf("\tShould map list with elements\n");
  int numbers[] = {0, 1};
  add_to_list(list, numbers);
  add_to_list(list, numbers + 1);
  List_ptr mapped_list_2 = map(list, &increment_number_element);
  assert(mapped_list_2->length == 2);
  assert(*(int *)mapped_list_2->first->element == 1);
  assert(*(int *)mapped_list_2->last->element == 2);
  printf("\t\t--passed\n\n");
}

int main(void)
{
  test_create_list();
  test_create_node();
  test_get_node();
  test_add_to_list();
  test_add_to_start();
  test_insert_at();
  test_reverse();
  test_map();

  return 0;
}