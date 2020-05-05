#include "./test.h"
#include "../list.c"
void assert(char *msg, Status actual, Status expected)
{
  if (actual == expected)
  {
    printf("✅ %s", msg);
  }
  else
  {
    printf("❌ %s", msg);
  }
}
void test_add_to_end(List *sample_list)
{
  Status actual = add_to_end(sample_list, 1);
  assert("add new element at last", actual, Success);
}
