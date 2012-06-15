#include <stdio.h>
#include <inttypes.h>

int palindrome(uint64_t base, uint64_t number) {
  uint64_t inverted = 0, aux = number;
  while (aux) {
    inverted *= base;
    inverted += aux % base;
    aux /= base;
  }
  return (inverted == number);
}

int main() {
  const uint64_t limit = 1000000;
  uint64_t sum = 0;
  uint64_t i;
  for (i = 1; i < limit; i++) {
    if (palindrome(2, i) && palindrome(10, i)) {
      sum += i;
    }
  }
  printf("%" PRIu64 "\n", sum);
  return 0;
}