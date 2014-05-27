/* insertion_sort.c
 * In place insertion sort with integers.
 *
 * Copyright 2014 Dana Silver
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAYLEN(x) (sizeof(x) / sizeof(x[0]))

void sort(int *array, int arrayLength) {
  int i, j, x;

  for (i = 1; i < arrayLength; i++) {
    x = array[i];
    j = i;
    while (j > 0 && array[j - 1] > x) {
      array[j] = array[j - 1];
      j--;
    }
    array[j] = x;
  }
}

void print_array(int *array, int arrayLength) {
  int i;
  for (i = 0; i < arrayLength; i++)
    if (i == arrayLength - 1)
      printf("%d", array[i]);
    else
      printf("%d, ", array[i]);
  printf("\n");
}

int main() {
  int array[5] = {45, 6, 3, 8, 12};
  int arrayLength = ARRAYLEN(array);
  printf("Unsorted: ");
  print_array(array, arrayLength);

  sort(array, arrayLength);

  printf("Sorted: ");
  print_array(array, arrayLength);

  return 0;
}