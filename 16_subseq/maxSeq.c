#include <stddef.h>
size_t maxSeq(int * array, size_t n) {
  if (n == 0) {return 0;}
  size_t maxLen = 1;
  size_t current = 1;
  for (size_t i = 1; i < n; i++) {
    if (array[i] > array[i-1]){
      current++;
    } else {
      if (current > maxLen) {
	maxLen = current;
      }
      current = 1;
    }
  }
  if (current > maxLen) {
      maxLen = current;
  }
  return maxLen;
}
