#include <stdio.h>

inline int fraction_eq(int a, int b, int c, int d) {
  return a * d == b * c;
}

int unorthodox_cancelling(int a, int b) {
  if (a % 10 == 0 && b % 10 == 0)
    return 0;  // trivial
  int a1 = a / 10, a2 = a % 10;
  int b1 = b / 10, b2 = b % 10;
  if ((a1 == b1 && fraction_eq(a2, b2, a, b)) ||
      (a1 == b2 && fraction_eq(a2, b1, a, b)) ||
      (a2 == b1 && fraction_eq(a1, b2, a, b)) ||
      (a2 == b2 && fraction_eq(a1, b1, a, b))) {
    return 1;
  }
  return 0;
}

unsigned long gcd(int a, int b) {
  if (a == b) return a;
  return (a < b) ? gcd(a, b-a) : gcd(a-b, b);
}

int main() {
  int i, j;
  unsigned long pa = 1, pb = 1;
  for (i = 10; i < 100; i++) {
    for (j = i+1; j < 100; j++) {
      if (unorthodox_cancelling(i, j)) {
        printf("Fraction: %d/%d\n", i, j);
        pa *= i;
        pb *= j;
      }
    }
  }
  printf("Product = %lu/%lu = %lu/%lu\n",
         pa, pb, pa/gcd(pa, pb), pb/gcd(pa, pb));
  return 0;
}
