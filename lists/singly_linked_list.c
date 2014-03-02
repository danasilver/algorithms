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

/* Print a singly linked list. */
void print_list(Node* root) {
  while (root) {
    printf("%i ", root->data);
    root = root->next;
  }
  printf("\n");
}

/* Reverse the order of a singly linked list. */
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

/* Insert a node at the head of the singly linked list. */
Node* insert(Node* root, int data) {
  Node* new_root = (Node*)malloc(sizeof(Node));
  new_root->data = data;
  new_root->next = root;

  return new_root;
}

/* Return the next node in a singly linked list. */
Node* next(Node* node) {
  return node->next;
}

/* Find a node in the singly linked list or return null. */
Node* find(Node* root, int key) {
  while (root) {
    if (root->data == key) {
      return root;
    }
    else {
      root = root->next;
    }
  }
  return NULL;
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

  Node* exists = find(list, 23);
  if (exists != NULL) {
    printf("%i exists!\n", exists->data);
    printf("%i is the data on the next node.\n", next(exists)->data);
  } else {
    printf("%i doesn't exist!\n", 23);
  }

  return 0;
}
