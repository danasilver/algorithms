/* doubly_linked_list.c
 * A generic doubly linked list implementation.
 *
 * Copyright 2014 Dana Silver
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} Node;

void print_list(Node* root) {
  while (root) {
    printf("%i ", root->data);
    root = root->next;
  }
  printf("\n");
}

Node* insert(Node* root, int data) {
  Node* new_root = (Node*)malloc(sizeof(Node));
  new_root->data = data;
  new_root->next = root;
  root->prev = new_root;

  return new_root;
}

Node* insertAtEnd(Node* root, int data) {
  Node* new_tail = (Node*)malloc(sizeof(Node));
  new_tail->data = data;

  while (root->next) {
    root = root->next;
  }

  root->next = new_tail;
  new_tail->prev = root;
}

Node* reverse(Node* root) {
  Node* temp = 0;
  while (root) {
    temp = root->prev;
    root->prev = root->next;
    root->next = temp;
    root = root->prev;
  }
  return temp->prev;
}

Node* next(Node* node) {
  return node->next;
}

Node* prev(Node* node) {
  return node->prev;
}

int main() {
  Node* list;
  list = (Node*)malloc(sizeof(Node));

  list->data = 23;
  list = insert(list, 24);
  list = insert(list, 45);
  print_list(list);

  insertAtEnd(list, 67);
  print_list(list);

  list = reverse(list);
  print_list(list);
}