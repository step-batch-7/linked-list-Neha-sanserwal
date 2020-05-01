
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

    list = add_first_node(list, node);
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
    list = add_first_node(list, node);
    return Success;
  }

  node->next = list->head;
  list->head = node;
  return Success;
}

Status remove_from_start(List_ptr list)
{
  if (!list->head)
  {
    return Failure;
  }

  Node_ptr p_walk = list->head;
  list->head = p_walk->next;
  list->count = list->count - 1;
  free(p_walk);
  Status status = Success;
  return Success;
}
Status remove_from_end(List_ptr list)
{
  if (!list->head)
  {
    return Failure;
  }
  list->count = --list->count;
  Node_ptr p_walk = list->head;
  if (list->count == 1)
  {
    free(p_walk);
    list->head = NULL;
    list->last = NULL;
    return Success;
  }
  while (!p_walk->next->next)
  {
    p_walk = p_walk->next;
  }
  free(p_walk->next);
  list->last = p_walk;
  return Success;
}

Status does_exist(int value, List_ptr list)
{
  Node_ptr p_walk = list->head;
  while (p_walk)
  {
    if (p_walk->value == value)
    {

      return Success;
    }
    p_walk = p_walk->next;
  }
  return Failure;
}
Status add_unique(List_ptr list, int value)
{
  if (does_exist(value, list))
  {
    return Failure;
  }
  list->count = ++list->count;
  add_to_end(list, value);
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  if (position == 0)
  {
    return add_to_start(list, value);
  }
  if (position > list->count)
  {
    return add_to_end(list, value);
  }
  Node_ptr p_walk = list->head;
  Node_ptr node = create_node(value);
  for (int i = 2; i < position; i++)
  {
    p_walk = p_walk->next;
  }
  node->next = p_walk->next;
  p_walk->next = node;
  return Success;
}

void display(List_ptr list)
{
  printf("%d", list->count);
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d \n", p_walk->value);
    p_walk = p_walk->next;
  }
}