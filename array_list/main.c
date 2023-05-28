#include "array_list.h"
#include <stdio.h>

void add_data_end(Array_list *list){
  printf("input your data to be added to the end\n");
  int data;
  scanf("%d", &data);
  array_list_add_end(list, data);
}

void add_data_pos(Array_list *list){
  printf("input your data to be added and position\n");
  int data;
  int pos;
  scanf("%d %d", &data, &pos);
  array_list_add_pos(list, data, pos);
}

void remove_data_pos(Array_list *list){
  printf("input position to be deleted\n");
  int pos;
  scanf("%d", &pos);
  array_list_remove_pos(list, pos);
}

int main(int argc, char **argv){
  Array_list *list = array_list_create(8);
  int chosen_option;
  chosen_option = -1;
  while(chosen_option != 5){
    printf("Select action:\n"
           "1. Print array_list\n"
           "2. Add data to end\n"
           "3. Add data to position\n"
           "4. Remove data from position\n"
           "5. Exit\n");
    scanf("%d", &chosen_option);
    switch (chosen_option) {
    case 1:
      array_list_print(list);
      break;
    case 2:
      add_data_end(list);
      break;
    case 3:
      add_data_pos(list);
      break;
    case 4:
      remove_data_pos(list);
      break;
    default:
      break;
    }
  }
  array_list_destroy(list);
  return 0;
}
