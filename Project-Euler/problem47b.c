#include <stdio.h>
#include <string.h>

#define MAX (1024*1024lu)

char sieve[MAX];

void fill_sieve() {
  unsigned long i, j;
  for (i = 2; i < MAX; i++)
    sieve[i] = 1;
  sieve[0] = sieve[1] = 0;
  for (i = 2; i < MAX; i++)
    if (sieve[i])
      for (j = 2 * i; j < MAX; j += i)
        sieve[j] = 0;
}

int distinct_prime_factors(unsigned long n) {
  int d = 0;
  unsigned long i;
  for (i = 2; i <= n; i++) {
    if (sieve[i] && n % i == 0) {
      d++;
      while (n % i == 0) n /= i;
    }
  }
  return d;
}

unsigned long find_first(int d) {
  unsigned long n = 4, j;
  for (n = 4;  ; n++) {
    for (j = 0; j < d; j++) {
      if (sieve[n+j] || distinct_prime_factors(n + j) != d)
        break;
    }
    if (j == d) return n;
    n += j;
  }
}


int main() {
  const int n = 4;
  fill_sieve();
  unsigned long i, r = find_first(n);
  printf("The first %d consecutive numbers to have %d distinct prime factors are:", n, n);
  for (i = 0; i < n; i++)
    printf(" %lu", r + i);
  printf("\n");
  return 0;
}

