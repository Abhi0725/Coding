/* UVa 10665 - Diatribe against Pigeonholes */

#include <stdio.h>
#include <string.h>

typedef struct {
  int n, c;
} cel;

int N;
cel v[26];
cel r[26];
int m[26];

int celcmp(const void *a, const void *b) {
  cel *aa = (cel*)a, *bb = (cel*)b;
  if (aa->n != bb->n) return bb->n - aa->n;
  return aa->c - bb->c;
}

void org() {
  int p=0,q=N-1,i=0,tmp,jj,j,k;
  memset(m,0,sizeof(m));
  while (p<q) {
    for (i=0;i<N;i++)
      if (!m[i]) break;
    m[i] = 1;
    for (k=i+1;k<N;k++)
      if (!m[k]) break;
    jj = 0;
    for (j=k+1;j<N;j++) {
      if (v[j].n != v[k].n) break;
      if (!m[j]) jj = j;
    }
    if (!jj || v[k].c < v[i].c) j = k;
    else j = jj;
    m[j] = 1;
    if (v[i].c < v[j].c) {
      memcpy(r+p,v+i,sizeof(cel));
      memcpy(r+q,v+j,sizeof(cel));
    } else {
      memcpy(r+p,v+j,sizeof(cel));
      memcpy(r+q,v+i,sizeof(cel));
    }
    p++;
    q--;
  }
  if (p==q) {
    for (i=0;i<N;i++)
      if (!m[i]) break;
    memcpy(r+p,v+i,sizeof(cel));
  }
}

int main() {
  int M,c,i;
  scanf("%d",&M);
  while (M--) {
    scanf("%d",&N);
    for (i=0;i<N;i++) {
      v[i].c = 'A' + i;
      v[i].n = 0;
    }
    while ((c = getchar())!='#') {
      if (c != '\n') v[c-'A'].n++;
    }
    qsort(v,N,sizeof(cel),celcmp);
    org();
    printf("%c",(char)r[0].c);
    for (i=1;i<N;i++) printf(" %c",(char)r[i].c);
    printf("\n");
    printf("%d",r[0].n);
    for (i=1;i<N;i++) printf(" %d",r[i].n);
    printf("\n");
  }
  return 0;
}
