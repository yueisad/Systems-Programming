//merge sort
#include<stdio.h>


void MergeSort(int numbers[], int i, int k) {
   int j;

   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition

      // Recursively sort left and right partitions
      MergeSort(numbers, i, j);
      MergeSort(numbers, j + 1, k);

      // Merge left and right partition in sorted order
      Merge(numbers, i, j, k);
   }
}

   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
   }

   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
   }

   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
   }
}
  int mergedNumbers[mergedSize];    // Temporary array for merged numbers
   int mergePos;                     // Position to insert merged number
   int leftPos;                      // Position of elements in left partition
   int rightPos;                     // Position of elements in right partition

   mergePos = 0;
   leftPos = i;                      // Initialize left partition position
   rightPos = j + 1;                 // Initialize right partition position

   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if (numbers[leftPos] < numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;

      }
      ++mergePos;
   }
int main(void) {
   int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
   const int NUMBERS_SIZE = 8;
   int i;

   printf("UNSORTED: ");
   for (i = 0; i < NUMBERS_SIZE; ++i) {
      printf("%i ", numbers[i]);
   }
   printf("\n");

   MergeSort(numbers, 0, NUMBERS_SIZE - 1);

   printf("SORTED: ");
   for (i = 0; i < NUMBERS_SIZE; ++i) {
      printf("%i ", numbers[i]);
   }
   printf("\n");

   return 0;
}
