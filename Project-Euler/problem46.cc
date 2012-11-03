#include <cstdio>
#include <cstring>
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

int conjecture_holds(int n) {
  int i, perfect_square = 0;
  for (i = 1; 2*(i + perfect_square) < n; i += 2) {
    perfect_square += i;
    if (sieve[n - 2*perfect_square]) return 1;
  }
  return 0;
}

int find() {
  int i = 9;
  for (i = 9; sieve[i] || conjecture_holds(i); i += 2) ;
  return i;
}

int main() {
  fill_sieve();
  printf("%d\n", find());
  return 0;
}
