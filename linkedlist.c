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