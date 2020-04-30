#include <stdio.h>
#include "list.h"

void print_options()
{
  printf("(a) add a number to the end of the list\n(b) add a number to the start of the list\n(c)display list (d)exit\n");
  printf("Please enter the alphabet of the operation you would like to perform\n");
}

int main(void)
{
  char option;
  int value;
  Status status;
  List_ptr list = create_list();
  print_options();
  scanf("%c", &option);
  while (1)
  {

    switch (option)
    {
    case 'a':
      printf("Enter a value:");
      scanf("%d", &value);
      status = add_to_end(list, value);
      break;
    case 'b':
      printf("Enter a value:");
      scanf("%d", &value);
      status = add_to_start(list, value);
      break;
    case 'c':
      display(list);
      break;
    case 'd':
      return 0;
      break;
    default:
      printf("Please enter valid option.\n\n");
      break;
    }
    print_options();
    scanf(" %c", &option);
  }

  return 0;
}