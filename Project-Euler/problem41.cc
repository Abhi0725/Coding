#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX (1024*1024lu)

using namespace std;

char sieve[MAX];

void fill_sieve() {
  unsigned long i, j;
  fill_n(sieve, MAX, 1);
  sieve[0] = sieve[1] = 0;
  for (i = 2; i < MAX; i++)
    if (sieve[i])
      for (j = 2 * i; j < MAX; j += i)
        sieve[j] = 0;
}

inline int is_prime(unsigned long n) {
  unsigned long i, lim = sqrt(n) + 2;
  if (n < MAX) return sieve[n];
  for (i = 2; i < lim; i++)
    if (sieve[i] && n % i == 0)
      return 0;
  return 1;
}

inline unsigned long long to_n(int *v, int d) {
  unsigned long long r = 0;
  for (int i = 0; i < d; i++)
    r = r * 10 + v[i];
  return r;
}

int main() {
  int v[] = {9,8,7,6,5,4,3,2,1};
  fill_sieve();
  for (int d = 9; d >= 1; d--) {
    sort(v, v+9);
    reverse(v, v+d);
    do {
      unsigned long long n = to_n(v, d);
      if (is_prime(n)) {
        printf("%llu is the largest n-digit pandigital prime!\n", n);
        return 0;
      }
    } while (prev_permutation(v, v+d));
  }
  return 0;
}
