/* UVa 10921 - Problem B: Find the Telephone */

#include <stdio.h>

int main() {
  char c;
  while ((c = getchar()) != EOF) {
    if (c>='A' && c<='Z') {
      c = c - (c >= 'S') - (c >= 'Z');
      c = (c-'A')/3+'2';
    }
    printf("%c", c);
  }
  return 0;
}
