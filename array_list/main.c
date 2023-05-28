#include "array_list.h"

int main(int argc, char **argv){
  Array_list *list = array_list_create(8);
  printf("Select action:\n"
          "1. Print array_list\n"
          "2. Add data to end\n"
          "3. Add data to position\n"
          "4. Remove data from position\n");
  return 0;
}
