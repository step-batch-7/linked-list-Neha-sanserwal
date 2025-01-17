#ifndef __LIST_H
#define __LIST_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
typedef enum
{
  Failure,
  Success
} Status;

typedef struct node
{
  int value;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct
{
  Node *head;
  Node *last;
  int count;
} List;

typedef List *List_ptr;

List_ptr create_list(void);

Status add_to_end(List_ptr, int value);
Status add_to_start(List_ptr, int value);
Status insert_at(List_ptr, int value, int position);
Status add_unique(List_ptr, int value);

void display(List_ptr);

Status remove_from_start(List_ptr);
Status remove_from_end(List_ptr);
Status remove_at(List_ptr, int position);

Status remove_first_occurrence(List_ptr, int value);
Status remove_all_occurrences(List_ptr, int value);

int does_exist(int value, List_ptr list);

Status clear_list(List_ptr); // Removes all elements in the list

void destroy_list(List_ptr); // Frees the elements and the list structure from memory
List_ptr add_first_node(List_ptr list, Node_ptr node);
Node_ptr walk_to(Node_ptr p_walk , int from, int position);
Node_ptr create_node(int value);
List_ptr assign_head_and_tail(List_ptr list, Node_ptr ptr);
void free_node(Node_ptr node);
#endif