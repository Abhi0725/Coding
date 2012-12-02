#include <cstdio>
#include <algorithm>

#define MAX (11234)

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

int to_n(int *v, int d) {
  int r = 0;
  for (int i = 0; i < d; i++)
    r = r * 10 + v[i];
  return r;
}

int to_v(int n, int *v) {
  int i = 0;
  while (n) {
    v[i++] = n%10;
    n /= 10;
  }
  reverse(v, v+i);
  return i;
}

bool is_perm(int a, int b) {
  int digits[10];
  fill_n(digits, 10, 0);
  while (a) {
    digits[a%10]++;
    a /= 10;
  }
  while (b) {
    digits[b%10]--;
    b /= 10;
  }
  for (int i = 0; i < 10; i++)
    if (digits[i] != 0)
      return false;
  return true;
}


int main() {
  int d, n2, n3, v2[4];
  fill_sieve();
  for (int n = 1000; n < 10000; n++) {
    if (sieve[n]) {
      d = to_v(n, v2);
      while (next_permutation(v2, v2 + d)) {
        n2 = to_n(v2, d);
        n3 = n2 + (n2 - n);
        if (n3 < 10000 && sieve[n2] && sieve[n3] && is_perm(n, n3)) {
          printf("%d %d %d\n", n, n2, n3);
        }
      }
    }
  }
  return 0;
}
