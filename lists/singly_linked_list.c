/* singly_linked_list.c
 * A generic singly linked list implementation.
 *
 * Copyright 2014 Dana Silver
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void print_list(Node* root) {
  while (root) {
    printf("%i ", root->data);
    root = root->next;
  }
  printf("\n");
}

Node* reverse(Node* root) {
  Node* new_root = 0;
  while (root) {
    Node* next = root->next;
    root->next = new_root;
    new_root = root;
    root = next;
  }
  return new_root;
}

Node* insert(Node* root, int data) {
  Node* new_root;
  new_root = (Node*)malloc(sizeof(Node));
  new_root->data = data;
  new_root->next = root;

  return new_root;
}

int main() {
  Node* list;
  list = (Node*)malloc(sizeof(Node));


  list->data = 23;
  list = insert(list, 24);
  list = insert(list, 45);
  print_list(list);

  list = reverse(list);
  print_list(list);

  return 0;
}