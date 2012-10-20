// Idea:
//   We want A*B=C. Let a, b, c be the number of digits of A, B, C.
//   So a+b+c=9 and a+b-1 <= c <= a+b (because of A*B=C). Thus c = 4.

#include <stdio.h>
#include <math.h>

// Inserts all digits from n into digits_set.
// Return 0 if n contains the digit 0 or there is a repeated digit.
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

int check(int a, int b, int digits_set) {
  if (!insert(a, &digits_set)) return 0;
  if (!insert(b, &digits_set)) return 0;
  return digits_set == 0x3fe;  // 1 to 9.
}

int pandigital(int n) {
  int digits_set = 0;
  if (!insert(n, &digits_set)) return 0;
  int a, b, lim = sqrt(n) + 1;
  for (a = 1; a < lim; a++) {
    if (n % a == 0) {
      b = n/a;
      if (check(a, b, digits_set)) {
        printf("%d x %d = %d\n", a, b, n);
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  int i, sum = 0;
  for (i = 1234; i < 10000; i++)
    if (pandigital(i))
      sum += i;
  printf("%d\n", sum);
  return 0;
}
