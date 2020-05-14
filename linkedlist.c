#include "linkedlist.h"

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(LinkedList));

  if (list != NULL)
  {

    list->first = NULL;
    list->last = NULL;
    list->length = 0;
  }

  return list;
}

Node_ptr create_node(Element value)
{
  Node_ptr node = malloc(sizeof(Node));

  if (node != NULL)
  {
    node->element = value;
    node->next = NULL;
  }

  return node;
}

Node_ptr get_node(List_ptr list, unsigned pos)
{
  if (pos >= list->length)
    return NULL;

  Node_ptr selected_node = list->first;

  for (unsigned curr_pos = 0; curr_pos < pos; curr_pos++)
  {
    selected_node = selected_node->next;
  }

  return selected_node;
}

Status add_to_list(List_ptr list, Element value)
{
  Node_ptr new_node = create_node(value);

  if (new_node == NULL)
    return Failure;

  Node_ptr *ptr_to_set = &list->first;

  if (list->first != NULL)
  {
    ptr_to_set = &list->last->next;
  }

  *ptr_to_set = new_node;
  list->last = new_node;
  list->length++;
  return Success;
}

Status add_to_start(List_ptr list, Element value)
{
  Node_ptr new_node = create_node(value);

  if (new_node == NULL)
    return Failure;

  new_node->next = list->first;
  list->first = new_node;

  if (list->last == NULL)
    list->last = new_node;

  list->length++;
  return Success;
}

Status insert_at(List_ptr list, Element element, int position)
{
  if (position > list->length || position < 0)
    return Failure;

  if (position == 0)
    return add_to_start(list, element);

  Node_ptr new_node = create_node(element);

  if (new_node == NULL)
    return Failure;

  Node_ptr previous_node = get_node(list, position - 1);
  new_node->next = previous_node->next;
  previous_node->next = new_node;

  if (position == list->length)
    list->last = new_node;

  list->length++;
  return Success;
}

List_ptr reverse(List_ptr list)
{
  List_ptr reversed_list = create_list();

  Node_ptr curr_node = list->first;

  while (curr_node != NULL)
  {
    add_to_start(reversed_list, curr_node->element);
    curr_node = curr_node->next;
  }

  return reversed_list;
}