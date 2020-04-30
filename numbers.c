#include <stdio.h>
#include "list.h"
void printOptions()
{
  printf("(a) add a number to the end of the list\n(b) add a number to the start of the list\n");
}
int main(void)
{
  List_ptr list = create_list();
  char option;
  printOptions();
  scanf("%c", &option);
  return 0;
}