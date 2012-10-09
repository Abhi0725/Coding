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
