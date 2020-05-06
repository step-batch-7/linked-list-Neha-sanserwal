#include "./test.h"
#include "../list.c"

void test_add_to_end()
{
  List_ptr sample_list = create_list();
  Status actual = add_to_end(sample_list, 1);
  assert("should add new element at last.", actual, Success);
}
void test_add_to_start()
{
  List_ptr sample_list = create_list();
  Status actual = add_to_start(sample_list, 1);
  assert(" should add new element at start.", actual, Success);
}

void test_insert_at()
{
  List_ptr sample_list = create_list();
  Status actual = insert_at(sample_list, 2, 0);
  assert("should insert Element at 0th position.", actual, Success);

  actual = insert_at(sample_list, 0, 0);
  assert("should insert Element at 0th position.", actual, Success);

  actual = insert_at(sample_list, 1, 1);
  assert("should insert Element in the middle.", actual, Success);

  actual = insert_at(sample_list, 3, 3);
  assert("should insert Element at end.", actual, Success);
}

void test_remove_from_start()
{
  List_ptr sample_list = create_list();
  add_to_end(sample_list, 1);
  add_to_end(sample_list, 1);
  Status actual = remove_from_start(sample_list);
  assert("should remove element from start if elements are more than one.", actual, Success);
  actual = remove_from_start(sample_list);
  assert("should remove element from start if element is only one.", actual, Success);

  sample_list = create_list();
  actual = remove_from_start(sample_list);
  assert("should give failure when there is no element.", actual, Failure);
}

void test_remove_from_end()
{
  List_ptr sample_list = create_list();
  add_to_end(sample_list, 1);
  add_to_end(sample_list, 1);
  Status actual = remove_from_end(sample_list);
  assert("should remove element from start if elements are more than one.", actual, Success);
  actual = remove_from_end(sample_list);
  assert("should remove element from start if element is only one.", actual, Success);

  sample_list = create_list();
  actual = remove_from_end(sample_list);
  assert("should give failure when there is no element.", actual, Failure);
}