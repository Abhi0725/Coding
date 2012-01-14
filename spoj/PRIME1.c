#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

// More than sqrt(1000000000)
#define LIMIT 32768
int crivo[LIMIT];

int tmp_crivo[100100];


void fill_crivo() {
  int n = LIMIT;
  int i, j;
  memset(crivo, 1, sizeof(crivo));
  crivo[0] = crivo[1] = 0;
  for (i = 2; i < n; i++) {
    if (crivo[i]) {
      for (j = 2*i; j < n; j += i) {
        crivo[j] = 0;
      }
    }
  }
}


int main() {
  int t;
  int64_t begin, end;
  long int i, j;
  long int start_at, end_at;
  scanf("%d", &t);
  fill_crivo();
  while (t--) {
    scanf("%"PRIi64" %"PRIi64, &begin, &end);
    memset(tmp_crivo, 1, sizeof(tmp_crivo));
    long int limit = (uint64_t) ceil(sqrt((double) end)) + 1;
    if (begin <= 2)
      begin = 2;
    for (i = 0; i <= limit; i++) {
      if (crivo[i]) {
        start_at = 2*i - begin;
        if (start_at < 0)
          start_at += (((-start_at) + i - 1)/i) * i;
        end_at = end - begin;
        for (j = start_at; j <= end_at; j += i) {
          tmp_crivo[j] = 0;
        }
      }
    }
    for (i = 0; i <= end - begin; i++) {
      if (tmp_crivo[i])
        printf("%" PRIi64 "\n", i + (uint64_t) begin);
    }
    if (t > 0)
      printf("\n");
  }
  return 0;
}
