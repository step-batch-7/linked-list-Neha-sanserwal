#include <stdio.h>
#include "list.h"

char *menu[13] = {"(a) add a number to the end of the list",
                  "(b) add a number to the start of the list",
                  "(c) insert a number at a given position in the list",
                  "(d) add a unique item on the list at the end(if it already exists, do not insert)",
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
  int value, position;
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
    case 'c':
      printf("Enter a value and position :");
      scanf("%d %d", &value, &position);
      status = insert_at(list, value, position);
      print_status(status, "inserting number ");
      break;
    case 'd':
      printf("Enter a unique value:");
      scanf("%d", &value);
      status = add_unique(list, value);
      print_status(status, "Adding unique number ");
      break;
    case 'e':
      status = remove_from_start(list);
      print_status(status, "Removing number from start ");
      break;
    case 'f':
      status = remove_from_end(list);
      print_status(status, "Removing number from end ");
      break;
    case 'g':
      printf("Enter a position to remove:");
      scanf("%d", &position);
      status = remove_at(list, position);
      print_status(status, "Removing number ");
      break;
    case 'h':
      printf("Enter a value: ");
      scanf("%d", &value);
      status = remove_first_occurrence(list, value);
      print_status(status, "Removing first occurrence");
      break;
    case 'i':
      printf("Enter a value: ");
      scanf("%d", &value);
      status = remove_all_occurrences(list, value);
      print_status(status, "Removing all occurrences");
      break;
    case 'j':
      status = clear_list(list);
      break;
    case 'k':
      printf("Enter a value to search:");
      scanf("%d", &value);
      int count = does_exist(value, list);
      if (count == -1)
      {
        printf("Number don't exist.");
      }
      else
      {
        printf("Number found at %d", count);
      }

      break;
    case 'l':
      display(list);
      break;
    case 'm':
      destroy_list(list);
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