#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIEVE (512ll * 1024ll)

char sieve[MAX_SIEVE];

void fill_sieve() {
  long i, j;
  memset(sieve, 0, sizeof(sieve));
  sieve[0] = sieve[1] = 1;
  for (i = 2; i < MAX_SIEVE; i++)
    if (!sieve[i])
      for (j = 2 * i; j < MAX_SIEVE; j += i)
        sieve[j] = 1;
  for (i = 0; i < MAX_SIEVE; i++)
    sieve[i] = !sieve[i];
}

int is_prime(long n) {
  if (n < MAX_SIEVE) return sieve[n];
  long i;
  for (i = 0; i < MAX_SIEVE && i*i <= n; i++)
    if (sieve[i] && n % i == 0) return 0;
  if (n > (MAX_SIEVE-1) * (MAX_SIEVE-1)) {
    printf("Error: Out of bound.\n");
    exit(-1);
  }
  return 1;
}

long solve(double ratio) {
  long i = 0, j, inc = 0, curr = 1, n_primes = 0, n_numbers = 1;
  do {
    i++;
    inc += 2;
    for (j = 0; j < 4; j++) {
      curr += inc;
      n_primes += is_prime(curr);
      n_numbers++;
    }
//    printf("i = %ld, n_primes = %ld, n_numbers = %ld, curr ratio = %.8lf\n",
//           i, n_primes, n_numbers, n_primes * 1.0 / n_numbers);
  } while (n_primes * 1.0 / n_numbers >= ratio);
  return 1+2*i;
}

int main() {
  fill_sieve();
  printf("%ld\n", solve(0.1));
  return 0;
}
