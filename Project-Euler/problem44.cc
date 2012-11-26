#include <cstdio>
#include <cmath>

typedef long long int lld;

inline bool is_pentagonal(lld n) {
  lld d = 1 + 24*n;
  lld d_sqrt = sqrt(d);
  return (d_sqrt * d_sqrt == d) && (d_sqrt % 6 == 5);
}

inline lld pentagonal(lld i) {
  return i * (3*i - 1) / 2;
}

void print_and_check(lld idx1, lld idx2, lld diff, lld sum) {
  lld p1 = pentagonal(idx1), p2 = pentagonal(idx2);
  if ((p1 + p2 != sum) || (p1 - p2 != diff)) {
    fprintf(stderr, "Error: p[%lld] = %lld, p[%lld] = %lld. ", idx1, p1, idx2, p2);
    fprintf(stderr, "Found sum = %lld, diff = %lld, but actually sum = %lld, diff = %lld\n",
            sum, diff, p1 + p2, p1 - p2);
    return;
  }
  printf("p[%lld] = %lld, p[%lld] = %lld. Sum = %lld, Diff = %lld\n",
         idx1, p1, idx2, p2, sum, diff);
}

int main() {
  lld delta, idx, curr_diff, curr_sum;
  lld limit;
  lld sol_idx1, sol_idx2, sol_diff;
  bool done = false;
  for (limit = 1024; !done; limit *= 2) {
    printf("Limit = %lld\n", limit);
    for (delta = 1; true; delta += 1) {
      curr_diff = curr_sum = delta * (3 * delta - 1) / 2;
      if (curr_diff >= limit) break;
      for (idx = 1; !done; idx++) {
        curr_diff += 3*delta;
        if (curr_diff >= limit) break;
        curr_sum += 6*idx + 3*delta - 4;
        if (is_pentagonal(curr_diff) && is_pentagonal(curr_sum)) {
          print_and_check(idx + delta, idx, curr_diff, curr_sum);
          if (!done || curr_diff < sol_diff) {
            sol_idx1 = idx + delta;
            sol_idx2 = idx;
            sol_diff = curr_diff;
          }
          done = true;
          break;
        }
      }
    }
  }
  printf("\n\n");
  lld p1 = pentagonal(sol_idx1), p2 = pentagonal(sol_idx2);
  printf("p[%lld] = %lld, p[%lld] = %lld. Sum = %lld, Diff = %lld\n",
         sol_idx1, p1, sol_idx2, p2, p1 + p2, p1 - p2);
  return 0;
}
