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

Node_ptr create_node(Element value){
  Node_ptr node = malloc(sizeof(Node));
  
  if(node != NULL){
    node->element = value;
    node->next = NULL;
  }

  return node;
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