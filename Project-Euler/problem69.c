// Idea:
//   F(n) = n / phi(n) = p1/(p1 - 1) * p2/(p2 - 1) * ... * pk/(pk - 1)
// where p1, p2, ..., pk are all distinct prime numbers dividing n.
// Thus:
// a) F(n1) == F(n2) if n1 and n2 are composed of the same prime numbers.
// b) F(n) <= F(p1 * p2 * ... * pn) where pn is the biggest prime dividing n.
// So n<=LIM for which n/phi(n) is a maximum is the biggest primorial number <= LIM.
// [Primorial numbers = product of the first successive primes]

#include <stdio.h>
#include <string.h>

#ifndef LIM
 #define LIM 1000000
#endif

#define MAX_SIEVE (1024)

char sieve[MAX_SIEVE];

void fill_sieve() {
  int i, j;
  memset(sieve, 0, sizeof(sieve));
  sieve[0] = sieve[1] = 1;
  for (i = 2; i < MAX_SIEVE; i++)
    if (!sieve[i])
      for (j = 2 * i; j < MAX_SIEVE; j += i)
        sieve[j] = 1;
  for (i = 0; i < MAX_SIEVE; i++)
    sieve[i] = !sieve[i];
}

int main() {
  unsigned long p, primorial;
  unsigned long lim = LIM;
  fill_sieve();

  primorial = 1;
  for (p = 2; primorial * p < lim; p++)
    if (sieve[p])
      primorial *= p;
  printf("%lu\n", primorial);
  return 0;
}
