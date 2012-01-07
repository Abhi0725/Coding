#include <stdio.h> 

int main() {
  unsigned long i,j,c,p,max;
  unsigned long f;
  while(scanf("%lu %lu",&i,&j)==2) {
    printf("%lu %lu ",i,j);
    if (i>j) { i^=j^=i^=j; }
    max=1;
    for (p=i;p<=j;p++) {
      c=1;
      f=p;
      while (f!=1) {
         c++;
         f = (f%2) ? 3*f+1 : f/2;
      }
      if (c>max) max=c;
    }
    printf("%lu\n", max);
  }
  return 0;
}
