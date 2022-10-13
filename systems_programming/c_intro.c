// "New" means new compared to previous level
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int TOTAL_NUMS = 3;

void ScrambleNums(int* remainNums, int* scramNums, bool* numAdded, int numCnt) {
   int i;

   if (numCnt == TOTAL_NUMS) {
      for (i = 0; i < numCnt; ++i) {
         printf("%d", scramNums[i]);
      }
      printf("\n");
   }
   else {
      for (i = TOTAL_NUMS - 1; i >= 0; --i) { // New: This line changed
         if (!numAdded[i]) {
            numAdded[i] = true;
            scramNums[numCnt] = remainNums[i];

            ScrambleNums(remainNums, scramNums, numAdded, numCnt + 1);

            numAdded[i] = false;
         }
      }
   }
}

int main(void) {
   int* numsToScramble = NULL;
   int* resultNums = NULL;
   bool* numAdded = NULL;

   numsToScramble = (int*)malloc(sizeof(int) * TOTAL_NUMS);
   resultNums = (int*)malloc(sizeof(int) * TOTAL_NUMS);
   numAdded = (bool*)malloc(sizeof(int) * TOTAL_NUMS);

   numAdded[0] = false;
   numAdded[1] = false;
   numAdded[2] = false;

   numsToScramble[0] = 6;
   numsToScramble[1] = 4;
   numsToScramble[2] = 0;

   ScrambleNums(numsToScramble, resultNums, numAdded, 0);

   return 0;
}