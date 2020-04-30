#include <stdio.h>
#include "list.h"

void printOptions()
{
  printf("(a) add a number to the end of the list\n(b) add a number to the start of the list\n");
}

int main(void)
{
  char option;
  int value;
  List_ptr list = create_list();
  printOptions();
  scanf("%c", &option);

  switch (option)
  {
  case 'a':
    printf("Enter a value:");
    scanf("%d", &value);
    Status status = add_to_end(list, value);
    break;

  default:
    break;
  }
  return 0;
}