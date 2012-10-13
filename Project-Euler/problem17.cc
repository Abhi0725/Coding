#include <cstdio>
#include <string>

using namespace std;

string first_cardinals[] = {
  "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
  "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

string second_digit[] = {
  "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

bool NumberToWords(int n, string* str) {
  if (n <= 0 || n > 1000) return false;
  if (n >= 1000) {
    NumberToWords(n/1000, str);
    str->append(" thousand");
    if (n % 1000) {
      str->append(" ");
      NumberToWords(n%1000, str);
    }
  } else if (n >= 100) {
    NumberToWords(n/100, str);
    str->append(" hundred");
    if (n % 100) {
      str->append(" and ");
      NumberToWords(n%100, str);
    }
  } else {
    if (n >= 20) {
      str->append(second_digit[n/10]);
      if (n%20) str->append(" ");
      n = n % 10;
    }
    str->append(first_cardinals[n]);
  }
  return true;
}


//                     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
int first_numbers[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int second_digit2[] =  {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};

int HowManyLetters(int n) {
  if (n <= 0 || n > 9999) return 0;
  if (n >= 1000) {
    return 8 /* thousand */ + HowManyLetters(n/1000) + HowManyLetters(n%1000);
  } else if (n >= 100) {
    if (n % 100)
      return 7 /* hundred */ + 3 /* and */ + HowManyLetters(n/100) + HowManyLetters(n%100);
    else
      return 7 /* hundred */ + HowManyLetters(n/100) + HowManyLetters(n%100);
  } else if (n >= 20) {
    return second_digit2[n/10] + HowManyLetters(n%10);
  } else {
    return first_numbers[n];
  }
}

int main() {
  int i, j, total = 0;
  string str;
  for (i = 1; i <= 1000; i++) {
    str.clear();
    NumberToWords(i, &str);
    for (j = 0; j < str.size(); j++)
      total += str[j] >= 'a' && str[j] <= 'z';
  }
  printf("%d\n", total);
}
