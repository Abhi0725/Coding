/* Problem 10598 - Find the Latitude */

#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279
#endif

int main() {
  int t = 1, k;
  double n, R;
  while (1) {
    scanf("%lf %lf", &R, &n);
    if (!R && !n) break;
    printf("Case %d:\n", t++);
    for (k = 1; k < 11; k++) {
      printf("%.5lf\n", 360/(2*M_PI)*acos(n/(2*M_PI*R*k))-n*180/(M_PI*R));
    }
  }
  return 0;
}
