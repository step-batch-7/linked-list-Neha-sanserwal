
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

Status add_to_start(List_ptr list, int value)
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

    list->head->next = node;
    list->head = node;
  }
  list->count = ++list->count;
  return Success;
}

void display(List_ptr list)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d\n", p_walk->value);
    p_walk = p_walk->next;
  }
}