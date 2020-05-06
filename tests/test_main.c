#include "./test.h"
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
int main(void)
{
  List_ptr sample_list = create_list();
  test_add_to_end(sample_list);
  return 0;
}