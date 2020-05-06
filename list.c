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
  if (!list)
  {
    return Failure;
  }
  if (!list->head)
  {

    list = add_first_node(list, node);
    ++list->count;
    return Success;
  }
  list->last->next = node;
  list->last = node;
  ++list->count;
  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr node = create_node(value);
  if (list->head == NULL)
  {
    list = add_first_node(list, node);
    ++list->count;
    return Success;
  }
  node->next = list->head;
  list->head = node;
  ++list->count;
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
  return Success;
}

Status remove_from_end(List_ptr list)
{
  Node_ptr p_walk = list->head;
  if (!p_walk)
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
  p_walk = walk_to(p_walk, 2, list->count);
  list->last = p_walk;
  p_walk->next = NULL;
  free(p_walk->next);
  list->count = list->count - 1;
  return Success;
}

Status remove_at(List_ptr list, int position)
{
  Node_ptr p_walk = list->head;
  if (position > list->count - 1 || position < 0 || !p_walk)
  {
    return Failure;
  }
  if (position == list->count - 1)
  {
    return remove_from_end(list);
  }
  if (position == 0)
  {
    return remove_from_start(list);
  }
  p_walk = walk_to(p_walk, 1, position);
  Node_ptr temp = p_walk->next;
  p_walk->next = temp->next;
  free(temp);
  --list->count;
  return Success;
}

int does_exist(int value, List_ptr list)
{
  int count = -1;
  Node *p_walk = list->head;
  for (int i = 0; i < list->count; i++)
  {
    if (p_walk->value == value)
    {
      return i;
    }
    p_walk = p_walk->next;
  }
  return count;
}

Status add_unique(List_ptr list, int value)
{
  if (does_exist(value, list) != -1)
  {
    return Failure;
  }
  add_to_end(list, value);
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  if (position > list->count || position < 0)
  {
    return Failure;
  }
  if (position == 0)
  {
    return add_to_start(list, value);
  }
  if (position == list->count)
  {
    return add_to_end(list, value);
  }
  Node_ptr p_walk = list->head;
  Node_ptr node = create_node(value);
  p_walk = walk_to(p_walk, 1, position);
  node->next = p_walk->next;
  p_walk->next = node;
  ++list->count;
  return Success;
}

Status clear_list(List_ptr list)
{
  while (list->count)
  {
    Node_ptr p_walk = list->head;
    list->head = p_walk->next;
    free(p_walk);
    list->count = list->count - 1;
  }
  list = assign_head_and_tail(list, NULL);
  if (list->count == 0)
  {
    return Success;
  }
  return Failure;
}
void destroy_list(List_ptr list)
{
  clear_list(list);
  free(list);
}

Status remove_first_occurrence(List_ptr list, int value)
{
  int position = does_exist(value, list);
  if (position == -1)
  {
    return Failure;
  }
  remove_at(list, position);

  return Success;
}

Status remove_all_occurrences(List_ptr list, int value)
{

  Status status = remove_first_occurrence(list, value);
  if (!status)
  {
    return Failure;
  }
  while (status)
  {
    status = remove_first_occurrence(list, value);
  }
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