#include <stdio.h>

//                     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
int first_numbers[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int second_digit[] =  {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};

int how_many_letters(int n) {
  if (n <= 0 || n > 9999) return 0;
  if (n >= 1000)
    return 8 /* thousand */ + how_many_letters(n/1000) + how_many_letters(n%1000);
  else if (n >= 100 && n % 100 != 0)
    return 7 /* hundred */ + 3 /* and */ + how_many_letters(n/100) + how_many_letters(n%100);
  else if (n >= 100 && n % 100 == 0)
    return 7 /* hundred */ + how_many_letters(n/100) + how_many_letters(n%100);
  else if (n >= 20)
    return second_digit[n/10] + how_many_letters(n%10);
  else
    return first_numbers[n];
}

int main() {
  int i, total = 0;
  for (i = 1; i <= 1000; i++)
    total += how_many_letters(i);
  printf("%d\n", total);
}
