#include "./test.h"
#include "../list.c"

void test_add_to_end()
{
  List_ptr sample_list = create_list();
  Status actual = add_to_end(sample_list, 1);
  assert("should add new element at last", actual, Success);
}
void test_add_to_start()
{
  List_ptr sample_list = create_list();
  Status actual = add_to_start(sample_list, 1);
  assert(" should add new element at start", actual, Success);
}

void test_insert_at()
{
  List_ptr sample_list = create_list();
  Status actual = insert_at(sample_list, 2, 0);
  assert("should insert Element at 0th position", actual, Success);

  actual = insert_at(sample_list, 0, 0);
  assert("should insert Element at 0th position", actual, Success);

  actual = insert_at(sample_list, 1, 1);
  assert("should insert Element in the middle", actual, Success);

  actual = insert_at(sample_list, 3, 3);
  assert("should insert Element at end", actual, Success);
}