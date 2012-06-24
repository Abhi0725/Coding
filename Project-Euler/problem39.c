#include <stdio.h>
#include <string.h>
#include <math.h>

#define LIM 1000

int main() {
  int freq[LIM + 1];
  int a, b, c, h;
  int p, max;
  memset(freq, 0, sizeof(freq));
  for (a = 1; a < LIM; a++) {
    for (b = a; b < LIM; b++) {
      h = a*a + b*b;
      for (c = 1; c*c < h; c++) ;
      if (c*c == h && a + b + c <= LIM) {
        freq[a+b+c]++;
      }
    }
  }
  max = 0;
  for (p = 1; p <= LIM; p++) {
    if (freq[p] > freq[max]) {
      max = p;
    }
  }
  printf("For p=%d there are %d solutions.\n", max, freq[max]);
}
