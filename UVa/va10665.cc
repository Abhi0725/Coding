#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct parcels {
  int n;
  char c;

  bool operator<(const parcels& other) const {
    if (n != other.n) return n > other.n;
    return c < other.c;
  }
};

int N;

int main() {
  int N, M, c, i, j;
  vector<parcels> v, vv;
  v.resize(26);
  scanf("%d", &M);
  while (M--) {
    scanf("%d", &N);
    for (i=0; i<N; i++) {
      v[i].c = 'A' + i;
      v[i].n = 0;
    }
    while ((c = getchar()) != '#') {
      if (c != '\n') v[c-'A'].n++;
    }
    // Generate solution.
    sort(v.begin(), v.begin()+N);
    vv.clear();
    for (i = 0; i < N; i += 2) {
      vv.push_back(v[i]);
    }
    for (i = N-N%2-1; i >= 0; i -= 2) {
      vv.push_back(v[i]);
    }
    // Rearrange to get the first alphabetically solution.
    for (i = 0; i < N; i++) {
      for (j = N-1; j > N-1-i && j > i; j--)
        if (vv[i].n == vv[j].n && vv[i].c > vv[j].c)
          swap(vv[i], vv[j]);
      if (i < N/2 && vv[i].c > vv[N-1-i].c)
        swap(vv[i], vv[N-1-i]);
    }
    // Output.
    for (i = 0; i < N; i++)
      printf("%s%c", (i!=0)?" ":"", vv[i].c);
    printf("\n");
    for (i = 0; i < N; i++)
      printf("%s%d", (i!=0)?" ":"", vv[i].n);
    printf("\n");
  }
  return 0;
}
