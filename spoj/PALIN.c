#include <stdio.h>
#include <string.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

void round_to_palindrome(char* input, char* output) {
  int n = strlen(input);
  char * input_begin = input;
  char * input_end = input + (n - 1)/2;
  while (input <= input_end) {
    *output++ = *input++;
  }
  if (n % 2 == 0)
    *output++ = *input_end;
  input = input_end - 1;
  while (input >= input_begin) {
    *output++ = *input--;
  }
  *output = '\0';
}

int next_palindrome(char* palin) {
  int i, carry_one = 0;
  int n = strlen(palin);
//  if (n % 2 == 0) {
//    palin[(n-1)/2]++;
//    palin[n/2]++;
//  } else {
//    palin[n/2]++;
//  }
  if (palin[n/2] == '9') {
    palin[(n-1)/2] = palin[n/2] = '0';
    carry_one = 1;
  } else {
    palin[(n-1)/2] = palin[n/2] = 1 + palin[n/2];
    carry_one = 0;
  }
  for (i = 1; carry_one && palin[n/2 + i]; i++) {
    if (palin[(n-1)/2 - i] == '9') {
      palin[(n-1)/2 - i] = palin[n/2 + i] = '0';
    } else {
      palin[(n-1)/2 - i]++;
      palin[n/2 + i]++;
      carry_one = 0;
    }
  }
  if (carry_one) {
    // the number is '1' + palin[0:n-1] + '1'
    // the caller needs to preappend '1'
    palin[n-1] = '1';
  }
  return carry_one;
}

int main() {
  int t, carry_one;
  char buffer[1000010];
  char palin[1000010];
  scanf("%d", &t);
  while (t--) {
    scanf("%s", buffer);
    round_to_palindrome(buffer, palin);
    if (strcmp(palin, buffer) <= 0) {
      carry_one = next_palindrome(palin);
    } else {
      carry_one = 0;
    }
    if (!carry_one) {
      printf("%s\n", palin);
    } else {
      printf("1%s\n", palin);
    }
  }
}
