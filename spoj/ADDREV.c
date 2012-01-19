#include <stdio.h>

unsigned rev(unsigned x) {
  unsigned r = 0;
  while (x%10 == 0) {
    x /= 10;
  }
  while (x) {
    r = 10*r + x%10;
    x /= 10;
  }
  return r;
}

unsigned int sum(unsigned int a, unsigned int b) {
  unsigned int ra = rev(a);
  unsigned int rb = rev(b);
  return rev(ra + rb);
}

int main() {
  int t;
  unsigned int a, b;
  scanf("%d", &t);
  while (t--) {
    scanf("%u %u", &a, &b);
    printf("%u\n", sum(a,b));
  }
  return 0;
}
