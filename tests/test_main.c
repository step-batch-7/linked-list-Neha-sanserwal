#include "./test.h"

Status assert_lists(List_ptr actual, List_ptr expected)
{
  if (!(actual->count == expected->count))
  {
    printf("%d %d", actual->count, expected->count);
    return Failure;
  }
  if (actual->count == expected->count && expected->count == 0)
  {
    return Success;
  }
  Node_ptr p_walkA = actual->head;
  Node_ptr p_walkB = expected->head;
  while (!p_walkB)
  {
    if (p_walkB->value != p_walkA->value)
    {

      return Failure;
    }
    p_walkB = p_walkB->next;
    p_walkA = p_walkA->next;
  }
  return Success;
}
void assert(char *msg, Status status, List_ptr actual, List_ptr expected, Status expectedStatus)
{

  if (status == expectedStatus && assert_lists(actual, expected) == Success)
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
  printf("\nremove_first_occurrence : \n");
  test_remove_first_occurrence();
  printf("\nremove_all_occurrences : \n");
  test_remove_all_occurrences();
  return 0;
}