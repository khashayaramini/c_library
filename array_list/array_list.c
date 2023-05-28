#include "array_list.h"
#include <stdlib.h>
// #include <stdio.h>
// #include <stdlib.h>

Array_list *array_list_create(int length){
  Array_list *array_list = malloc(sizeof(Array_list));
  array_list->list = malloc(sizeof(int) * length);
  array_list->length = length;
  array_list->last = -1;
  return array_list;
}

Array_list *array_list_add_end(Array_list *array_list, int data){
  if(array_list->last < array_list->length -1){
    array_list->last++;
    array_list->list[array_list->last] = data;
  }else{
    int *temp = malloc(sizeof(int) * array_list->length);
    temp = array_list->list;
    array_list->list = malloc(sizeof(int) * array_list->length * 2);
    for(int i = 0; i <= array_list->last; i++)
      array_list->list[i] = temp[i];
    free(temp);
    array_list->length *= 2;
    array_list->last++;
    array_list->list[array_list->last] = data;
  }
  return array_list;
}
Array_list *array_list_add_pos(Array_list *array_list, int data, int pos){
  if(array_list->last < array_list->length -1){
    for(int i = array_list->last; i > pos; i--)
      array_list->list[array_list->last + 1] = array_list->list[array_list->last];
    array_list->list[pos] = data;
    array_list->last++;
  }else{
    int *temp = malloc(sizeof(int) * array_list->length);
    temp = array_list->list;
    array_list->list = malloc(sizeof(int) * array_list->length * 2);
    for(int i = 0; i < pos - 1; i++)
      array_list->list[i] = temp[i];
    array_list->list[pos] = data;
    for(int i = pos; i < array_list->last; i++)
      array_list->list[i + 1] = temp[i];
    free(temp);
    array_list->length *= 2;
    array_list->last++;
    array_list->list[array_list->last] = data;
  }
  return array_list;
}

Array_list *array_list_remove_pos(Array_list *array_list, int pos){
  for(int i = pos; i <= array_list->last; i++)
    array_list->list[i] = array_list->list[i+1];
  array_list->last--;
  return array_list;
}
