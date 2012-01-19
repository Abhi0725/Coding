#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>

uint64_t Z(uint64_t n) {
  uint64_t zeros = 0;
  uint64_t i;
  for (i = 5; n/i > 0; i *= 5) {
    zeros += n/i;
  }
  return zeros;
}

int main() {
  int t;
  uint64_t N;
  scanf("%d", &t);
  while (t--) {
    scanf("%" PRIu64 "", &N);
    printf("%" PRIu64 "\n", Z(N));
  }
  return 0;
}
