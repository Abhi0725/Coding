// Idea:
// A fraction m/n is on the left side (sequence starts w/L) if and only if n > m.
// To understand how to continue this process, you can try to match the left or
// right subtrees with the root. Eventually this leads to Euclid's gcd algorithm.

#include <stdio.h>

int main() {
  unsigned long m, n;
  while (1) {
    scanf("%lu %lu", &m, &n);
    if (m == 1 && n == 1) break;
    while (m > 1 || n > 1) {
      if (m > n) {
        putchar('R');
        m -= n;
      } else {
        putchar('L');
        n -= m;
      }
    }
    putchar('\n');
  }
  return 0;
}
