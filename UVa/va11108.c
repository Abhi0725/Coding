/* UVa 11108 - Problem D: Tautology */

#include <stdio.h>
#include <string.h>

#define bit_at(n, i) (((n) & (1ll<<(i))) != 0)

int val;
char expr[101];
int pos;

int evaluate() {
  int a, b;
  char ep = expr[pos++];
  if (ep >= 'p' && ep <= 't') return bit_at(val, ep-'p');
  if (ep == 'N') return !evaluate();
  a = evaluate();
  b = evaluate();
  switch (ep) {
    case 'K': return (a && b);
    case 'A': return (a || b);
    case 'C': return !(a && !b);
    case 'E': return (a == b);
  }
  /* never happens */
  return 1;
}

int sat() {
  for (val = 0; val < (1<<5); val++) {
    pos = 0;
    if (!evaluate()) return 0;
  }
  return 1;
}

int main() {
  while (1) {
    scanf("%s", expr);
    if (expr[0] == '0') break;
    if (sat()) printf("tautology\n");
    else printf("not\n");
  }
  return 0;
}
