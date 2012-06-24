#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#define LIM_N 15
#define LIM_K 100

uint64_t M[LIM_N][LIM_K];

void dyn() {
  int i, j, k;
  memset(M, 0, sizeof(M));
  for (i = 0; i < LIM_N; i++)
    M[i][0] = 1;

  for (i = 1; i < LIM_N; i++) {
    for (j = 1; j < LIM_K; j++) {
      for (k = 0; k < i && k <= j; k++) {
        M[i][j] += M[i-1][j-k];
      }
    }
  }
}


int main() {
  int t;
  unsigned int a, b;
  dyn();
  scanf("%d", &t);
  while (t--) {
    scanf("%u %u", &a, &b);
    printf("%lu\n", M[a][b]);
  }
  return 0;
}
