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
  Status status;
  List_ptr list = create_list();
  printOptions();
  scanf("%c", &option);

  switch (option)
  {
  case 'a':
    printf("Enter a value:");
    scanf("%d", &value);
    status = add_to_end(list, value);
    display(list);
    break;
  case 'b':
    printf("Enter a value:");
    scanf("%d", &value);
    status = add_to_start(list, value);
    display(list);
    break;
  default:
    break;
  }
  return 0;
}