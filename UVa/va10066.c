/* Problem 10066 - The Twin Towers */

#include <stdio.h>
#include <string.h>

#define LIM 102
#define max(a,b) (((a) > (b)) ? (a) : (b))

int n1, n2;
int v1[LIM], v2[LIM];
int pd[LIM][LIM];

int solve() {
  int i, j;
  memset(pd, 0, sizeof(pd));
  for (i = n1-1; i >= 0; i--) {
    for (j = n2-1; j >= 0; j--) {
      pd[i][j] = max(pd[i+1][j], pd[i][j+1]);
      if (v1[i] == v2[j])
        pd[i][j] = max(pd[i][j], 1 + pd[i+1][j+1]);
    }
  }
  return pd[0][0];
}

int main() {
  int i, k=1;
  scanf("%d %d", &n1, &n2);
  while (n1 != 0 && n2 != 0) {
    for (i=0;i<n1;i++) scanf("%d", &v1[i]);
    for (i=0;i<n2;i++) scanf("%d", &v2[i]);
    printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", k++, solve());
    scanf("%d %d", &n1, &n2);
  }
}
