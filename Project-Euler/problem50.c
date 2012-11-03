#include <stdio.h>
#include <string.h>
#include <math.h>

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

inline int is_prime(unsigned long n) {
  if (n < MAX) return sieve[n];
  unsigned long i, lim = sqrt(n) + 2;
  for (i = 2; i < lim; i++)
    if (sieve[i] && n % i == 0)
      return 0;
  return 1;
}

int main() {
  const unsigned long lim = 1000000;
  unsigned long i, j, sum, longest_prime;
  int count, longest_count = -1;
  fill_sieve();
  for (i = 2; i < lim; i++) {
    if (is_prime(i)) {
      sum = i;
      count = 1;
      for (j = i+1; j + sum < lim; j++) {
        if (is_prime(j)) {
          sum += j;
          count++;
          if (count > longest_count && is_prime(sum)) {
            longest_count = count;
            longest_prime = sum;
          }
        }
      }
    }
  }
  printf("The longest sum of consecutive primes below %lu that adds to a prime, "
         "contains %d terms, and is equal to %lu.\n",
         lim, longest_count, longest_prime);
  return 0;
}
