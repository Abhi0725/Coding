// Idea:
//   R(n) = phi(n) / (n - 1)
// This is similar to problem69, however there is an important difference:
// the divisor is (n-1) instead of n.
// For phi(n)/n, the minimas are all the primorial numbers. With (n-1) this
// is not true anymore, however it is possible to see that all minimas are
// products of the k smallest primes.
// So the idea is to find the first primorial Nk=p1*p2*...*pk below the limit.
// The first number is either Nk or a composed of k-1 primes, that is, multiples
// of Nk/pk (i.e., it is 2*Nk/pk, 3*Nk/pk, ..., (pk-1)*Nk/pk, pk*Nk/pk = Nk).

#include <stdio.h>
#include <string.h>

#ifndef LIMNUM
 #define LIMNUM 15499
#endif
#ifndef LIMDEN
 #define LIMDEN 94744
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

unsigned long totient(unsigned long v) {
  unsigned long i, j, r = 1;
  for (i = 2; i <= v; i++) {
    if (v % i == 0) {
      v /= i;
      r *= (i - 1);
      while (v % i == 0) {
        v /= i;
        r *= i;
      }
    }
  }
  return r;
}

int main() {
  unsigned long p, resilients, number;
  unsigned long lim_num = LIMNUM, lim_den = LIMDEN;
  fill_crivo();

  number = resilients = 1;
  for (p = 2; ; p++) {
    if (crivo[p]) {
      resilients *= p - 1;
      number *= p;
      if (resilients * lim_den < (number-1) * lim_num)
        break;
    }
  }
  unsigned long base = number / p;
  printf("First primorial number found.\n");
  printf("R(%lu) = %lu/%lu < %lu/%lu.\nAnswer is in range %lu, %lu, ..., %lu (%lu possibilities).\n",
         number, resilients, number-1, lim_num, lim_den, 2*base, 3*base, number, p - 1);
  for (number = 2*base; number <= base * p; number += base) {
    resilients = totient(number);
    if (resilients * lim_den < (number-1) * lim_num)
      break;
  }
  printf("%lu is the smallest denominator having resilience R(%lu) = %lu/%lu < %lu/%lu.\n",
         number, number, resilients, number-1, lim_num, lim_den);
  return 0;
}
