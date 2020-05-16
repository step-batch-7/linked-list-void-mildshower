#include <stdio.h>
#include <assert.h>
#include "../linkedlist.h"

Element increment_number_element(Element number)
{
  Element incremented_number = malloc(sizeof(int));
  *(int *)incremented_number = *(int *)number + 1;
  return incremented_number;
}

Status is_even_number_element(Element number)
{
  return !(*(int *)number % 2);
}

Element add_number_elements(Element number1, Element number2)
{
  Element sum = malloc(sizeof(int));
  *(int *)sum = *(int *)number1 + *(int *)number2;
  return sum;
}

int function_call_count = 0;

void assert_element_value(Element number)
{
  assert(*(int *)number == function_call_count);
  function_call_count++;
}

Status are_number_elements_same(Element number1, Element number2)
{
  return *(int *)number1 == *(int *)number2;
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

  printf("\tShould increment all numbers by 1\n");
  int numbers[] = {0, 1};
  add_to_list(list, numbers);
  add_to_list(list, numbers + 1);
  List_ptr mapped_list_2 = map(list, &increment_number_element);
  assert(mapped_list_2->length == 2);
  assert(*(int *)mapped_list_2->first->element == 1);
  assert(*(int *)mapped_list_2->last->element == 2);
  printf("\t\t--passed\n\n");
}

void test_filter(void)
{
  printf("\n\nTesting filter\n\n");

  List_ptr list = create_list();
  printf("\tShould produce empty list when empty list is filtered\n");
  List_ptr filtered_list_1 = filter(list, &is_even_number_element);
  assert(filtered_list_1->length == 0);
  assert(filtered_list_1->first == NULL);
  assert(filtered_list_1->last == NULL);
  printf("\t\t--passed\n\n");

  printf("\tShould keep only even numbers\n");
  int numbers[] = {0, 1, 2};
  add_to_list(list, numbers);
  add_to_list(list, numbers + 1);
  add_to_list(list, numbers + 2);
  List_ptr filtered_list_2 = filter(list, &is_even_number_element);
  assert(filtered_list_2->length == 2);
  assert(*(int *)filtered_list_2->first->element == 0);
  assert(*(int *)filtered_list_2->last->element == 2);
  printf("\t\t--passed\n\n");
}

void test_reduce(void)
{
  printf("\n\nTesting reduce\n\n");

  List_ptr list = create_list();
  int numbers[] = {0, 1, 2};
  printf("\tShould give initial context back when reduced an empty list\n");
  Element sum1 = reduce(list, numbers, &add_number_elements);
  assert(*(int *)sum1 == 0);
  printf("\t\t--passed\n\n");

  printf("\tShould sum up all numbers\n");
  add_to_list(list, numbers + 1);
  add_to_list(list, numbers + 2);
  Element sum2 = reduce(list, numbers, &add_number_elements);
  assert(*(int *)sum2 == 3);
  printf("\t\t--passed\n\n");
}

void test_forEach(void)
{
  printf("\n\nTesting forEach\n\n");

  List_ptr list = create_list();
  printf("\tShould not call processor function when empty list is given\n");
  forEach(list, &assert_element_value);
  assert(function_call_count == 0);
  printf("\t\t--passed\n\n");

  printf("\tShould call processor function with each element\n");
  int numbers[] = {0, 1, 2};
  add_to_list(list, numbers);
  add_to_list(list, numbers + 1);
  add_to_list(list, numbers + 2);
  forEach(list, &assert_element_value);
  assert(function_call_count == 3);
  printf("\t\t--passed\n\n");
}

void test_remove_from_start(void)
{
  printf("\n\nTesting remove_from_start\n\n");

  List_ptr list = create_list();
  printf("\tShould give NULL when empty list is given to remove_from_start function\n");
  assert(remove_from_start(list) == NULL);
  printf("\t\t--passed\n\n");

  int numbers[] = {0, 1};
  printf("\tShould make the list empty when list with single element is given\n");
  add_to_list(list, numbers);
  assert(*(int *)remove_from_start(list) == 0);
  assert(list->length == 0);
  assert(list->first == NULL);
  assert(list->last == NULL);
  printf("\t\t--passed\n\n");

  printf("\tShould remove the first element\n");
  add_to_list(list, numbers);
  add_to_list(list, numbers + 1);
  assert(*(int *)remove_from_start(list) == 0);
  assert(list->length == 1);
  assert(*(int *)list->first->element == 1);
  assert(*(int *)list->last->element == 1);
  printf("\t\t--passed\n\n");
}

void test_remove_from_end(void)
{
  printf("\n\nTesting remove_from_end\n\n");

  List_ptr list = create_list();
  printf("\tShould give NULL when empty list is given to remove_from_end function\n");
  assert(remove_from_end(list) == NULL);
  printf("\t\t--passed\n\n");

  int numbers[] = {0, 1};
  printf("\tShould make the list empty when list with single element is given\n");
  add_to_list(list, numbers);
  assert(*(int *)remove_from_end(list) == 0);
  assert(list->length == 0);
  assert(list->first == NULL);
  assert(list->last == NULL);
  printf("\t\t--passed\n\n");

  printf("\tShould remove the last element\n");
  add_to_list(list, numbers);
  add_to_list(list, numbers + 1);
  assert(*(int *)remove_from_end(list) == 1);
  assert(list->length == 1);
  assert(*(int *)list->first->element == 0);
  assert(*(int *)list->last->element == 0);
  printf("\t\t--passed\n\n");
}

void test_remove_at(void)
{
  printf("\n\nTesting remove_at\n\n");

  List_ptr list = create_list();
  printf("\tShould give NULL when empty list is given to remove_at function\n");
  assert(remove_at(list, 0) == NULL);
  printf("\t\t--passed\n\n");

  int numbers[] = {0, 1, 2};
  printf("\tShould give NULL if negative position is given\n");
  add_to_list(list, numbers);
  assert(remove_at(list, -1) == NULL);
  printf("\t\t--passed\n\n");

  printf("\tShould give NULL if exceeded postion is given\n");
  assert(remove_at(list, 1) == NULL);
  printf("\t\t--passed\n\n");

  printf("\tShould make the list empty when list with single element is given\n");
  assert(*(int *)remove_at(list, 0) == 0);
  assert(list->length == 0);
  assert(list->first == NULL);
  assert(list->last == NULL);
  printf("\t\t--passed\n\n");

  printf("\tShould remove first element when first element's position is given\n");
  add_to_list(list, numbers);
  add_to_list(list, numbers + 1);
  add_to_list(list, numbers + 2);
  assert(*(int *)remove_at(list, 0) == 0);
  assert(list->length == 2);
  assert(*(int *)list->first->element == 1);
  assert(*(int *)list->last->element == 2);
  printf("\t\t--passed\n\n");

  printf("\tShould remove last element when last element's position is given\n");
  assert(*(int *)remove_at(list, 1) == 2);
  assert(list->length == 1);
  assert(*(int *)list->first->element == 1);
  assert(*(int *)list->last->element == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould remove a middle element\n");
  add_to_list(list, numbers);
  add_to_list(list, numbers + 2);
  assert(*(int *)remove_at(list, 1) == 0);
  assert(list->length == 2);
  assert(*(int *)list->first->element == 1);
  assert(*(int *)list->last->element == 2);
  printf("\t\t--passed\n\n");
}

void test_remove_first_occurrence(void)
{
  printf("\n\nTesting remove_first_occurrence\n\n");

  List_ptr list = create_list();
  int numbers[] = {0, 1, 2};
  printf("\tShould give NULL when empty list is given to remove_first_occurrence function\n");
  assert(remove_first_occurrence(list, numbers, &are_number_elements_same) == NULL);
  printf("\t\t--passed\n\n");

  printf("\tShould give NULL when no element matches\n");
  add_to_list(list, numbers);
  add_to_list(list, numbers + 1);
  assert(remove_first_occurrence(list, numbers + 2, &are_number_elements_same) == NULL);
  assert(list->length == 2);
  assert(*(int *)list->first->element == 0);
  assert(*(int *)list->last->element == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould remove the first occurrence when it is the first element\n");
  add_to_list(list, numbers);
  assert(*(int *)remove_first_occurrence(list, numbers, &are_number_elements_same) == 0);
  assert(list->length == 2);
  assert(*(int *)list->first->element == 1);
  assert(*(int *)list->last->element == 0);
  printf("\t\t--passed\n\n");

  printf("\tShould remove the first occurrence when it is the last element\n");
  assert(*(int *)remove_first_occurrence(list, numbers, &are_number_elements_same) == 0);
  assert(list->length == 1);
  assert(*(int *)list->first->element == 1);
  assert(*(int *)list->last->element == 1);
  printf("\t\t--passed\n\n");

  printf("\tShould remove the the single element when it matches\n");
  assert(*(int *)remove_first_occurrence(list, numbers + 1, &are_number_elements_same) == 1);
  assert(list->length == 0);
  assert(list->first == NULL);
  assert(list->last == NULL);
  printf("\t\t--passed\n\n");

  printf("\tShould remove first match from middle\n");
  add_to_list(list, numbers);
  add_to_list(list, numbers + 1);
  add_to_list(list, numbers + 2);
  assert(*(int *)remove_first_occurrence(list, numbers + 1, &are_number_elements_same) == 1);
  assert(list->length == 2);
  assert(*(int *)list->first->element == 0);
  assert(*(int *)list->last->element == 2);
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
  test_filter();
  test_reduce();
  test_forEach();
  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();
  test_remove_first_occurrence();

  return 0;
}