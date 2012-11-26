#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double freq[256];
char cipher[2048];
int N;

void read_frequencies(int n, char *files[]) {
  int i;
  double sum = 0;
  for (i = 0; i < 256; i++) freq[i] = 0;
  for (i = 0; i < n; i++) {
    FILE *fp = fopen(files[i], "r");
    if (!fp) {
      fprintf(stderr, "Error opening file %s\n", files[i]);
      exit(-1);
    }
    int c;
    while ((c = fgetc(fp)) != EOF) { freq[c]++; sum += 1; }
  }
  for (i = 0; i < 256; i++) freq[i] /= sum;
}

void read_cipher() {
  char input[4096];
  int i;
  scanf("%s", input);
  N = 1;
  memset(cipher, 0, sizeof(cipher));
  for (i = 0; i < strlen(input); i++) {
    if (input[i] == ',') N++;
    else if (input[i] >= '0' && input[i] <= '9')
      cipher[N-1] = cipher[N-1] * 10 + input[i] - '0';
  }
}

double similarity(double v1[256], double v2[256]) {
  int i;
  double numerator = 0, denominator1 = 0, denominator2 = 0;
  for (i = 0; i < 256; i++) {
    numerator += v1[i] * v2[i];
    denominator1 += v1[i] * v1[i];
    denominator2 += v2[i] * v2[i];
  }
  if (denominator1 == 0 || denominator2 == 0)
    return -1;
  return numerator / (sqrt(denominator1) * sqrt(denominator2));
}

void decipher(char password[3]) {
  int i, j, k;
  double f[3][256], sum[3], v[256], best_similarity[3], s;
  memset(sum, 0, sizeof(sum));
  memset(f, 0, sizeof(f));
  for (i = 0; i < N; i++) {
    sum[i%3] += 1;
    f[i%3][cipher[i]] += 1;
  }
  for (i = 0; i < 3; i++)
    for (j = 0; j < 256; j++)
      f[i][j] /= sum[i];
  best_similarity[0] = best_similarity[1] = best_similarity[2] = -1;
  for (i = 0; i < 3; i++) {
    for (k = 0; k < 256; k++) {
      for (j = 0; j < 256; j++)
        v[j] = f[i][j^k];
      s = similarity(v, freq);
      if (s > best_similarity[i]) {
        password[i] = k;
        best_similarity[i] = s;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  long i, sum = 0;
  char password[3];
  read_frequencies(argc-1, argv + 1);
  read_cipher();
  decipher(password);
  printf("Text:\n");
  for (i = 0; i < N; i++) {
    sum += cipher[i] ^ password[i % 3];
    printf("%c", cipher[i] ^ password[i % 3]);
  }
  printf("\n");
  printf("Sum of ASCII values of the original text: %ld\n", sum);
}
