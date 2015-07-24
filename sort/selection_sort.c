/* selection_sort.c
 * Selection sort with integers.
 *
 * Copyright 2014 Dana Silver
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAYLEN(x) (sizeof(x) / sizeof(x[0]))

void swap(int x, int y, int *px, int *py) {
  *px = y;
  *py = x;
}

void sort(int *array, int arrayLength) {
  int i, j, currMin;
  
  for (i = 0; i < arrayLength - 1; i++) {
    currMin = i;
    for (j = i + 1; i < arrayLength; i++) {
      if (array[j] < array[currMin]) {
	currMin = i;
      }
    }
    
    if (currMin != i) {
      swap(i, currMin, &i, &currMin);
    }
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
