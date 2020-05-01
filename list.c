
#include "list.h"
List_ptr assign_head_and_tail(List_ptr list, Node_ptr ptr)
{
  list->head = ptr;
  list->last = ptr;
  return list;
}

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  list = assign_head_and_tail(list, NULL);
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

Node_ptr walk_to(Node_ptr p_walk, int from, int position)
{
  for (int i = from; i < position; i++)
  {
    p_walk = p_walk->next;
  }
  return p_walk;
}

List_ptr add_first_node(List_ptr list, Node_ptr node)
{
  list = assign_head_and_tail(list, node);
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
  Node_ptr p_walk = list->head;
  if (!list->head)
  {
    return Failure;
  }

  if (list->count == 1)
  {
    free(p_walk);
    list = assign_head_and_tail(list, NULL);
    list->count = list->count - 1;
    return Success;
  }
  walk_to(p_walk, 2, list->count);
  free(p_walk->next);
  list->count = --list->count;
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
  p_walk = walk_to(p_walk, 2, position);
  node->next = p_walk->next;
  p_walk->next = node;
  return Success;
}

void display(List_ptr list)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d \n", p_walk->value);
    p_walk = p_walk->next;
  }
}