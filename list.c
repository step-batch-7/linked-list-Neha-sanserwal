
#include "list.h"
List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  if (!list->head)
  {
    list->head = node;
    list->last = node;
  }
  else
  {
    list->last->next = node;
    list->last = node;
  }
  list->count = ++list->count;
  return Success;
}