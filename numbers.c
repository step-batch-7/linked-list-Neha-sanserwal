#include <stdio.h>
#include "list.h"

char *menu[13] = {"(a) add a number to the end of the list",
                  "(b) add a number to the start of the list",
                  "(c) insert a number at a given position in the list",
                  "(d) add a unique item on the list at the end(if it alreay exists, do not insert)",
                  "(e) remove a number from the beginning of the list",
                  "(f) remove a number from the end of the list",
                  "(g) remove a number from a given position in the list",
                  "(h) remove first occurrence of a number",
                  "(i) remove all occurrences of a number",
                  "(j) clear the whole list",
                  "(k) check if a number exists in the list",
                  "(l) display the list of numbers",
                  "(m) exit"};

void print_options()
{
  for (int i = 0; i < 13; i++)
  {
    printf("%s\n", menu[i]);
  }

  printf("Please enter the alphabet of the operation you would like to perform\n");
}

int print_status(Status status, char *msg)
{
  if (status)
  {
    printf("%s was Successful\n", msg);
    return 0;
  }
  printf("%s was Failed\n", msg);
  return 0;
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
      add_to_end(list, value);
      break;
    case 'b':
      printf("Enter a value:");
      scanf("%d", &value);
      add_to_start(list, value);
      break;
    case 'e':
      status = remove_from_start(list);
      print_status(status, "Removing number from start ");
      break;
    case 'f':
      status = remove_from_end(list);
      print_status(status, "Removing number from start ");
      break;
    case 'k':
      printf("Enter a value to search:");
      scanf("%d", &value);
      status = does_exist(value, list);
      char *msg = "Finding number ";
      print_status(status, msg);
      break;
    case 'l':
      display(list);
      break;
    case 'm':
      return 0;
      break;
    default:
      printf("Please enter valid option.\n\n");
      break;
    }
    print_options();
    fflush(stdin);
    scanf(" %c", &option);
  }

  return 0;
}