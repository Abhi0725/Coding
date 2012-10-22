/* UVa 10930 - Problem D: A-Sequence */

#include <stdio.h>
#include <string.h>

int sum[1002];

int main() {
  int i, j, d, prev, is_a;
  int c = 1, n;
  while (scanf("%d", &n) == 1) {
    printf("Case #%d:", c++);
    memset(sum, 0, sizeof(sum));
    is_a = 1;
    prev = -1;
    for (i = 0; i < n; i++) {
      scanf("%d", &d);
      printf(" %d", d);
      if (prev >= d || sum[d]) is_a = 0;
      prev = d;
      if (is_a) {
        for (j = 1000-d; j >= 0; j--) {
          if (sum[j]) sum[j+d] = 1;
        }
        sum[d] = 1;
      }
    }
    if (is_a) printf("\nThis is an A-sequence.\n");
    else printf("\nThis is not an A-sequence.\n");
  }
  return 0;
}
