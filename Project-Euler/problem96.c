#include <stdio.h>
#include <string.h>

int sudoku[9][9];

int print() {
  int i, j;
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      printf("%d ", sudoku[i][j]);
      if (j%3 == 2) printf(" ");
    }
    printf("\n");
    if (i == 2 || i == 5) printf("\n");
  }
}

int solve(int pos) {
  int i, j, bi, bj, r;
  int posi = pos/9, posj = pos%9;
  int val[9];
  if (pos >= 9*9) return 1;
  if (sudoku[posi][posj]) return solve(pos + 1);
  for(i = 0; i < 9; i++) val[i] = 1;
  for(i = 0; i < 9; i++) {
    if (r = sudoku[posi][i])
      val[r-1] = 0;
    if (r = sudoku[i][posj])
      val[r-1] = 0;
  }
  bi = posi - (posi%3);
  bj = posj - (posj%3);
  for (i=0;i<3;i++)
    for (j=0;j<3;j++)
      if (r = sudoku[bi+i][bj+j])
        val[r-1] = 0;
  for (i=0;i<9;i++)
    if (val[i]) {
      sudoku[posi][posj] = i+1;
      if (solve(pos + 1)) return 1;
    }
  sudoku[posi][posj] = 0;
  return 0;
}

int main() {
  int i, j, sum = 0;
  char buffer[1024];
  while(1) {
    if (!fgets(buffer, sizeof(buffer), stdin)) break;
    if (buffer[strlen(buffer)-1] == '\n') buffer[strlen(buffer)-1] = '\0';
    printf("Solution for '%s':\n", buffer);
    for (i = 0; i < 9; i++) {
      fgets(buffer, sizeof(buffer), stdin);
      for (j = 0; j < 9; j++)
        sudoku[i][j] = buffer[j] - '0';
    }
    if (solve(0)) print();
    else printf("Error: no solution.\n");
    sum += 100*sudoku[0][0] + 10*sudoku[0][1] + 1*sudoku[0][2];
    printf("\n");
  }
  printf("The sum of the 3-digit numbers found in the top left corner of each solution is %d\n", sum);
  return 0;
}
