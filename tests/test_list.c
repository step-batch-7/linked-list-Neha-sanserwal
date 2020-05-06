#include "./test.h"
#include "../list.c"
List_ptr setExpectation(int *values, int length)
{
  List_ptr expected = create_list();
  expected->count = 0;
  if (length > 0)
  {
    expected->head = create_node(values[0]);
    expected->last = expected->head;
    expected->count = expected->count + 1;
  }
  for (int i = 1; i < length; i++)
  {
    Node_ptr node = create_node(values[i]);
    expected->last->next = node;
    expected->last = node;
    ++expected->count;
  }
  return expected;
}
void test_add_to_end()
{
  List_ptr sample_list = create_list();
  int values[] = {1};
  List_ptr expected = setExpectation(values, 1);
  Status status = add_to_end(sample_list, 1);
  assert("should add new element at last.", status, sample_list, expected, Success);
}
void test_add_to_start()
{
  List_ptr sample_list = create_list();
  Status status = add_to_start(sample_list, 1);
  int values[] = {1};
  List_ptr expected = setExpectation(values, 1);
  assert(" should add new element at start.", status, sample_list, expected, Success);
}

void test_insert_at()
{
  List_ptr sample_list = create_list();
  Status status = insert_at(sample_list, 2, 0);
  int values1[] = {2};
  List_ptr expected = setExpectation(values1, 1);
  assert("should insert Element at 0th position.", status, sample_list, expected, Success);

  int values2[] = {0, 2};
  expected = setExpectation(values2, 2);
  status = insert_at(sample_list, 0, 0);
  assert("should insert Element at 0th position.", status, sample_list, expected, Success);

  int values3[] = {0, 1, 2};
  expected = setExpectation(values3, 3);
  status = insert_at(sample_list, 1, 1);
  assert("should insert Element in the middle.", status, sample_list, expected, Success);

  int values4[] = {0, 1, 2, 3};
  expected = setExpectation(values4, 4);
  status = insert_at(sample_list, 3, 3);
  assert("should insert Element at end.", status, sample_list, expected, Success);
}

void test_remove_from_start()
{
  List_ptr sample_list = create_list();
  add_to_end(sample_list, 1);
  add_to_end(sample_list, 2);
  int values1[] = {2};
  List_ptr expected = setExpectation(values1, 1);
  Status status = remove_from_start(sample_list);

  assert("should remove element from start if elements are more than one.", status, sample_list, expected, Success);

  status = remove_from_start(sample_list);
  status = Success;
  int values2[] = {};
  expected = setExpectation(values2, 0);
  assert("should remove element from start if element is only one.", status, sample_list, expected, Success);

  int values3[] = {};
  expected = setExpectation(values3, 0);
  status = remove_from_start(sample_list);
  assert("should give failure when there is no element.", status, sample_list, expected, Failure);
}

void test_remove_from_end()
{
  List_ptr sample_list = create_list();
  add_to_end(sample_list, 1);
  add_to_end(sample_list, 2);
  Status status = remove_from_end(sample_list);
  int values1[] = {1};
  List_ptr expected = setExpectation(values1, 1);
  assert("should remove element from end if elements are more than one.", status, sample_list, expected, Success);
  status = remove_from_end(sample_list);
  int values2[] = {};
  expected = setExpectation(values2, 0);
  assert("should remove element from end if element is only one.", status, sample_list, expected, Success);
  sample_list = create_list();
  status = remove_from_end(sample_list);
  assert("should give failure when there is no element.", status, sample_list, expected, Failure);
}

void test_remove_at()
{
  List_ptr sample_list = create_list();
  add_to_end(sample_list, 1);
  add_to_end(sample_list, 2);
  add_to_end(sample_list, 3);
  add_to_end(sample_list, 4);
  Status status = remove_at(sample_list, 0);
  int values1[] = {2, 3, 4};
  List_ptr expected = setExpectation(values1, 3);
  assert("should remove element if position is 0.", status, sample_list, expected, Success);
  status = remove_at(sample_list, 1);
  int values2[] = {2, 4};
  expected = setExpectation(values2, 2);
  assert("should remove element from middle.", status, sample_list, expected, Success);

  status = remove_at(sample_list, 10);
  assert("should not remove element if position is invalid.", status, sample_list, expected, Failure);
  int values3[] = {2};
  expected = setExpectation(values3, 1);
  status = remove_at(sample_list, 1);
  assert("should remove element from last.", status, sample_list, expected, Success);
}

void test_add_unique()
{
  List_ptr sample_list = create_list();
  add_to_end(sample_list, 1);
  add_to_end(sample_list, 1);
  add_to_end(sample_list, 3);
  Status status = add_unique(sample_list, 1);
  int values1[] = {1, 1, 3};
  List_ptr expected = setExpectation(values1, 3);
  assert("should not add item if it is already present.", status, sample_list, expected, Failure);
  int values2[] = {1, 1, 3, 2};
  expected = setExpectation(values2, 4);
  status = add_unique(sample_list, 2);
  assert("should add item if it is not already present.", status, sample_list, expected, Success);
}

void test_clear_list()
{
  List_ptr sample_list = create_list();
  add_to_end(sample_list, 1);
  add_to_end(sample_list, 1);
  add_to_end(sample_list, 3);
  Status status = clear_list(sample_list);
  int values1[] = {};
  List_ptr expected = setExpectation(values1, 0);
  assert("should clear list and set count to zero.", status, sample_list, expected, Success);
}

void test_remove_first_occurrence()
{
  List_ptr sample_list = create_list();
  add_to_end(sample_list, 1);
  add_to_end(sample_list, 2);
  add_to_end(sample_list, 1);
  add_to_end(sample_list, 3);
  add_to_end(sample_list, 1);
  Status status = remove_first_occurrence(sample_list, 1);
  int values1[] = {2, 1, 3, 1};
  List_ptr expected = setExpectation(values1, 4);
  assert("should remove first of item in list if present.", status, sample_list, expected, Success);
  status = remove_first_occurrence(sample_list, 4);
  assert("should give failure if item is not present.", status, sample_list, expected, Failure);
}

void test_remove_all_occurrences()
{
  List_ptr sample_list = create_list();
  add_to_end(sample_list, 1);
  add_to_end(sample_list, 2);
  add_to_end(sample_list, 1);
  add_to_end(sample_list, 3);
  add_to_end(sample_list, 1);
  int values1[] = {2, 3};
  List_ptr expected = setExpectation(values1, 2);
  Status status = remove_all_occurrences(sample_list, 1);
  assert("should remove all occurrences of item in list if present.", status, sample_list, expected, Success);
  status = remove_all_occurrences(sample_list, 1);
  assert("should give failure if item is not present.", status, sample_list, expected, Failure);
}