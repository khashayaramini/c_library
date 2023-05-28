#include <stdio.h>
#include <stdlib.h>

typedef struct {
  void *next;
  int data;
} Node;

void print_menu() {
  printf("Please choose an option:\n");
  printf("\t1. Insert into list.\n");
  printf("\t2. Remove from list.\n");
  printf("\t3. Print list.\n");
  printf("\t4. Reset.\n");
  printf("\t5. Exit.\n");
}

Node *add_node(Node *head, int index, int data) {
  // invalid index to insert
  if (index < 0)
    return head;

  // insert to head
  if (index == 0) {
    Node *new = malloc(sizeof(Node));
    if (new == NULL)
      return head;
    new->data = data;
    new->next = head;
    return new;
  }

  // insert to middle
  if (head == NULL)
    return head;
  int current_index = 0;
  Node *current_node = head;
  while (current_node != NULL && current_index != index - 1) {
    current_node = current_node->next;
    current_index++;
  }
  if (current_node == NULL)
    return head;
  Node *new = malloc(sizeof(Node));
  if (new == NULL)
    return head;
  new->next = current_node->next;
  new->data = data;
  current_node->next = new;
  return head;
}

Node *remove_node(Node *head, int index) {
  // invalid index to remove
  if (index < 0)
    return head;

  // remove head
  if (index == 0) {
    Node *new_head = head->next;
    free(head);
    return new_head;
  }

  // remove from middle
  if (head == NULL)
    return head;
  int current_index = 0;
  Node *current_node = head;
  while (current_node != NULL && current_index != index - 1) {
    current_node = current_node->next;
    current_index++;
  }
  if (current_node->next == NULL)
    return head;
  Node *to_remove = current_node->next;
  if (to_remove == NULL)
    return head;
  Node *next = to_remove->next;
  free(to_remove);
  current_node->next = next;
  return head;
}

void print_list(Node *head) {
  Node *current_node = head;
  int current_index = 0;
  while (current_node != NULL) {
    printf("%d- %d \t->", current_index, current_node->data);
    current_node = current_node->next;
    current_index++;
  }
  printf("\n");
}

Node *reset_list(Node *head) {
  Node *current = head;
  while (current != NULL) {
    Node *to_remove = current;
    current = current->next;
    free(to_remove);
  }
  return NULL;
}

int main(int argc, char **argv) {
  print_menu();
  Node *head = NULL;
  int option = -1;
  int num_of_input;
  while (option != 5) {
    num_of_input = scanf("%d", &option);
    if (option != 5 && num_of_input == 1) {
      int index = -1;
      int data = 0;
      switch (option) {
      case 1:
        printf("Enter index:");
        scanf("%d", &index);
        printf("Enter data:");
        scanf("%d", &data);
        head = add_node(head, index, data);
        break;
      case 2:
        printf("Enter index:");
        scanf("%d", &index);
        head = remove_node(head, index);
        break;
      case 3:
        print_list(head);
        break;
      case 4:
        head = reset_list(head);
        break;
        break;
      }
    }
    print_menu();
  }
  return 0;
}
