#include <stdio.h>
#include <string.h>

// Inserts all digits from n into digits_set.
// Return 0 if n contains the digit 0 or if there is a repeated digit.
int insert(int n, int* digits_set) {
  int success = 1, digit;
  while (n > 0) {
    digit = n%10;
    success = success && !(*digits_set & (1<<digit)) && digit;
    *digits_set |= (1<<digit);
    n /= 10;
  }
  return success;
}

int main() {
  int i, j, digits_set;
  char number[10], max[] = "000000000";
  char* n_ptr;
  for (i = 1; i < 10000; i++) {
    digits_set = 0;
    n_ptr = number;
    for (j = 1; ; j++) {
      if (!insert(i*j, &digits_set)) {
        digits_set = 0;
        break;
      }
      n_ptr += sprintf(n_ptr, "%d", i*j);
      if (digits_set == 0x3fe) {  // Found
        printf("%5d multiplied (1..%d): %s\n", i, j, number);
        break;
      }
    }
    if (digits_set && strcmp(number, max) > 0)
      strcpy(max, number);
  }
  printf("Largest pandigital: %s\n", max);
  return 0;
}
