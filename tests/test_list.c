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

int main(void){
  test_create_list();

  return 0;
}