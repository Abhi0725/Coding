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

#define MAX_CRIVO (1024)

char crivo[MAX_CRIVO];

void fill_crivo() {
  int i, j;
  memset(crivo, 0, sizeof(crivo));
  crivo[0] = crivo[1] = 1;
  for (i = 2; i < MAX_CRIVO; i++)
    if (!crivo[i])
      for (j = 2 * i; j < MAX_CRIVO; j += i)
        crivo[j] = 1;
  for (i = 0; i < MAX_CRIVO; i++)
    crivo[i] = !crivo[i];
}

int main() {
  unsigned long p, primorial;
  unsigned long lim = LIM;
  fill_crivo();

  primorial = 1;
  for (p = 2; primorial * p < lim; p++)
    if (crivo[p])
      primorial *= p;
  printf("%lu\n", primorial);
  return 0;
}
