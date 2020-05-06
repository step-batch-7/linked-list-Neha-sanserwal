#include "./test.h"
void assert(char *msg, Status actual, Status expected)
{
  if (actual == expected)
  {
    printf("✅ %s\n", msg);
  }
  else
  {
    printf("❌ %s\n", msg);
  }
}
int main(void)
{
  printf("\nadd_to_end : \n");
  test_add_to_end();
  printf("\nadd_to_start: \n");
  test_add_to_start();
  printf("\nInsert_at : \n");
  test_insert_at();
  return 0;
}