/* UVa 11100 - Problem A: The Trip, 2007 */

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
  int n, i, j, n_packs, first_test_case = 1;
  int bags[10002];
  while (1) {
    scanf("%d", &n);
    if (!n) break;
    if (!first_test_case) printf("\n");
    first_test_case = 0;
    memset(bags, 0, sizeof(bags));
    for (i = 0; i < n; i++)
      scanf("%d", &bags[i]);
    sort(bags, bags + n);
    n_packs = i = 0;
    while (i < n) {
      for (j = 1; j + i < n; j++)
        if (bags[i] != bags[i+j])
          break;
      if (j > n_packs)
        n_packs = j;
      i += j;
    }
    printf("%d\n", n_packs);
    for (i = 0; i < n_packs; i++) {
      printf("%d", bags[i]);
      for (j = i + n_packs; j < n; j += n_packs)
        printf(" %d", bags[j]);
      printf("\n");
    }
  }
  return 0;
}
