#include "./test.h"
#include "../list.c"

void test_add_to_end(List *sample_list)
{
  Status actual = add_to_end(sample_list, 1);
  assert("should add new element at last", actual, Success);
}
void test_add_to_start(List *sample_list)
{
  Status actual = add_to_start(sample_list, 1);
  assert(" should add new element at start", actual, Success);
}
