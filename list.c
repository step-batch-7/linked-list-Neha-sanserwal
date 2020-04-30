
#include "list.h"
List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Node_ptr create_node(int value)
{
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

List_ptr add_first_node(List_ptr list, Node_ptr node)
{
  list->head = node;
  list->last = node;
  return list;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr node = create_node(value);
  list->count = ++list->count;
  if (!list->head)
  {
    add_first_node(list, node);
    return Success;
  }

  list->last->next = node;
  list->last = node;
  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr node = create_node(value);
  list->count = ++list->count;
  if (list->head == NULL)
  {
    add_first_node(list, node);
    return Success;
  }

  node->next = list->head;
  list->head = node;
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