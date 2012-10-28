#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
inline T to_n(int *v, int d) {
  T r = 0;
  for (int i = 0; i < d; i++)
    r = r * 10 + v[i];
  return r;
}

int main() {
  int v[] = {1,0,2,3,4,5,6,7,8,9};
  unsigned long long sum = 0;
  do {
    if (to_n<int>(v+1, 3) %  2 == 0 &&
        to_n<int>(v+2, 3) %  3 == 0 &&
        to_n<int>(v+3, 3) %  5 == 0 &&
        to_n<int>(v+4, 3) %  7 == 0 &&
        to_n<int>(v+5, 3) % 11 == 0 &&
        to_n<int>(v+6, 3) % 13 == 0 &&
        to_n<int>(v+7, 3) % 17 == 0) {
      sum += to_n<unsigned long long>(v, 10);
      printf("Found pandigital with unusual sub-string divisibility property: %llu\n",
             to_n<unsigned long long>(v, 10));
    }
  } while (next_permutation(v, v+10));
  printf("The sum of these numbers is %llu\n", sum);
  return 0;
}
