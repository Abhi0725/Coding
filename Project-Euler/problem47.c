#include <stdio.h>
#include <string.h>

#define MAX (1024*1024lu)

int distinct_prime_factors[MAX];

void count_prime_factors() {
  unsigned long i, j;
  memset(distinct_prime_factors, 0, sizeof(distinct_prime_factors));
  for (i = 2; i < MAX; i++) {
    if (!distinct_prime_factors[i]) {
      for (j = i; j < MAX; j += i)
        distinct_prime_factors[j]++;
    }
  }
}

unsigned long find_first(int d) {
  unsigned long n = 4, j;
  for (n = 4;  ; n++) {
    for (j = 0; j < d; j++) {
      if (distinct_prime_factors[n + j] != d)
        break;
    }
    if (j == d) return n;
    n += j;
  }
}


int main() {
  const int n = 4;
  count_prime_factors();
  unsigned long i, r = find_first(n);
  printf("The first %d consecutive numbers to have %d distinct prime factors are:", n, n);
  for (i = 0; i < n; i++)
    printf(" %lu", r + i);
  printf("\n");
  return 0;
}

