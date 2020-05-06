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
  printf("\nremove_from_start : \n");
  test_remove_from_start();
  printf("\nremove_from_end : \n");
  test_remove_from_end();
  printf("\nremove_at : \n");
  test_remove_at();
  printf("\nadd_unique : \n");
  test_add_unique();
  printf("\nclear_list : \n");
  test_clear_list();
  return 0;
}