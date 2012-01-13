#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;

bool to_rpn(const char exp[], char output[]) {
  vector<char> stack;
  int io = 0;
  int len = strlen(exp);
  for (int i = 0; i < len; i++) {
    const char c = exp[i];
    if (c >= 'a' && c <= 'z') {
      output[io++] = c;
    } else if (c == '*' || c == '+' || c == '/' || c == '-' ||
               c == '^' || c == '(') {
      stack.push_back(c);
    } else if (c == ')') {
      while (1) {
        if (stack.empty()) {
          fprintf(stderr, "Error! Got ')' and empty stack.\n");
          exit(-1);
        }
        const char s = stack.back();
        stack.pop_back();
        if (s == '(')
          break;
        else
          output[io++] = s;
      }
    }
  }
  output[io] = '\0';
  return stack.empty();
}

int main() {
  int n;
  char input[410], output[410];
  scanf("%d", &n);
  while (n--) {
    scanf("%s", input);
    if (!to_rpn(input, output)) {
      fprintf(stderr, "ended with non-empty stack\n");
    } else {
      printf("%s\n", output);
    }
  }
  return 0;
}
