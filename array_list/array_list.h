#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Array_list{
  int *list;
  int length;
  int last;
}Array_list;

Array_list *array_list_create(int length);
Array_list *array_list_add_end(Array_list *array_list, int data);
Array_list *array_list_add_pos(Array_list *array_list, int data, int pos);
Array_list *array_list_remove_pos(Array_list *array_list, int pos);

#endif
