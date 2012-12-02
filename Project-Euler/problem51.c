// Idea: Iterate on base 11 using the extra digit as the asterisk.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIEVE (1234567)

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

void print_placeholder(long placeholder) {
  char buffer[32];
  int i = 0, j;
  while (placeholder) {
    if (placeholder % 11 == 10) buffer[i++] = '*';
    else buffer[i++] = '0' + (placeholder % 11);;
    placeholder /= 11;
  }
  for (j = i-1; j >=0; j--)
    printf("%c", buffer[j]);
}

int has_asterisk(long placeholder) {
  while (placeholder) {
    if (placeholder % 11 == 10) return 1;
    placeholder /= 11;
  }
  return 0;
}

// returns 0 if placeholder starts with asterisk and d == 0.
long get_n(long placeholder, int d) {
  int mult = 1, n = 0;
  while (placeholder) {
    if (placeholder/11 == 10 && d == 0) return 0;
    int c = placeholder % 11;
    if (c == 10) n += mult * d;
    else n += mult * c;
    mult *= 10;
    placeholder /= 11;
  }
  return n;
}

int main() {
  fill_sieve();
  long placeholder = 0;
  int i, n_primes, n, min = 8;
  while (++placeholder) {
    if (has_asterisk(placeholder)) {
      n_primes = 0;
      for (i = 0; i < 10; i++) {
        n = get_n(placeholder, i);
        n_primes += sieve[n];
      }
      if (n_primes >= min)
        break;
    }
  }

  for (i = 0; i < 10; i++) {
    if (sieve[get_n(placeholder, i)]) {
      printf("Placeholder ");
      print_placeholder(placeholder);
      printf(": %d primes. First is %ld.\n",
             n_primes, get_n(placeholder, i));
      break;
    }
  }
  return 0;
}
