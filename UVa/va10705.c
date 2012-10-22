/* UVa 10705 - Problem A: The Fun Number System */

#include <stdio.h>
#include <string.h>

#define bit_at(n, i) (((n) & (1ll<<(i))) != 0)

int N;
int posibit[64];

int convert(long long* number) {
  int i, j;
  for (i = 0; i < N; i++)
    if (bit_at(*number, i) && !posibit[i])
      *number += 1ll << (i+1);
  const long long overflow_mask = ~((1ll << N) - 1);
  return !(*number & overflow_mask);
}

int main() {
  int n, i;
  long long number;
  char b[70];
  scanf("%d", &n);
  while (n-- > 0) {
    scanf("%d", &N);
    scanf("%s", b);
    for (i = 0; i < N; i++)
      posibit[N-i-1] = (b[i] == 'p');
    scanf("%lld", &number);
    if (!convert(&number)) {
      printf("Impossible\n");
      continue;
    }
    for (i = N-1; i >= 0; i--)
      printf("%d", bit_at(number, i));
    printf("\n");
  }
}
