#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include "lib.h"

using namespace std;

const int target = 5;

bool find_solution(map<ull, int> count, map<ull, ull> smallest, ull* solution) {
  map<ull, int>::const_iterator it;
  *solution = 0;
  for (it = count.begin(); it != count.end(); ++it)
    if (it->second == target)
      if (!*solution || *solution > smallest[it->first])
        *solution = smallest[it->first];
  return *solution != 0;
}

int main() {
  ull i = 1, c, canonical, solution;
  int n_digits = 0;
  char digits[100], *last_digit;
  map<ull, int> count;
  map<ull, ull> smallest;
  while (1) {
    c = i*i*i;
    last_digit = get_digits(c, digits);
    if (last_digit - digits != n_digits) {
      // Number of digits changed, we look for an answer now.
      if (find_solution(count, smallest, &solution)) {
        printf("%llu is the smallest cube\n", solution);
        return 0;
      }
      // No solution so far, must go on.
      // But the previous data is useless now:
      count.clear();
      smallest.clear();
    }
    n_digits = last_digit - digits;
    sort(digits, last_digit);
    reverse(digits, last_digit);
    canonical = digits_to_number<ull>(digits, last_digit);
    if (count.find(canonical) != count.end()) {
      count[canonical] += 1;
    } else {
      count[canonical] = 1;
      smallest[canonical] = c;
    }
    i++;
  }
  return 0;
}
