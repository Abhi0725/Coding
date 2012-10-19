#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAX (1024 * 1024)

char sieve[MAX];

void fill_sieve() {
  int i, j;
  fill_n(sieve, MAX, 1);
  sieve[0] = sieve[1] = 0;
  for (i = 2; i < MAX; i++)
    if (sieve[i])
      for (j = 2 * i; j < MAX; j += i)
        sieve[j] = 0;
}

int drop_left_digit(int v) {
  int k, first_digit = v;
  for (k = 0; first_digit/10 > 0; k++)
    first_digit /= 10;
  for ( ; k > 0; k--)
    first_digit *= 10;
  return v - first_digit;
}

int main() {
  vector<int> truncatable;
  int sum = 0;
  char left[MAX], right[MAX];
  fill_sieve();
  for (int i = 0; i < 10; i++)
    left[i] = right[i] = 1;

  for (int i = 10; i < MAX; i++) {
    const int l = drop_left_digit(i), r = i/10;
    left[i] = sieve[i] && sieve[l] && left[l];
    right[i] = sieve[i] && sieve[r] && right[r];
    if (left[i] && right[i]) {
      truncatable.push_back(i);
      sum += i;
    }
  }
  printf("Truncatable primes:");
  for (int i = 0; i < truncatable.size(); i++)
    printf(" %d", truncatable[i]);
  printf("\n");
  printf("Sum is %d\n", sum);
  return 0;
}
