/* 11080 - Problem G: Place the Guards */

#include <stdio.h>
#include <string.h>

int V;
int map[200][200];
int color[200];

int bipartition(int s, int clr, int count[]) {
  int i;
  color[s] = clr + 1;
  count[clr]++;
  for (i = 0; i < V; i++) {
    if (map[s][i]) {
      if (color[i] == clr + 1)
        return 0;
      if (!color[i]) {
        if (!bipartition(i, !clr, count))
          return 0;
      }
    }
  }
  return 1;
}

int calc() {
  int i, total = 0;
  int count[2];
  memset(color, 0, sizeof(color));
  for (i = 0; i < V; i++) {
    if (!color[i]) {
      count[0] = count[1] = 0;
      if (!bipartition(i, 0, count)) return -1;
      if (!count[0] || !count[1]) total += 1;
      else total += (count[0] < count[1]) ? count[0] : count[1];
    }
  }
  return total;
}

int main() {
  int T, f, t, e;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &V, &e);
    memset(map, 0, sizeof(map));
    while (e--) {
      scanf("%d %d", &f, &t);
      map[f][t] = map[t][f] = 1;
    }
    printf("%d\n",calc());
  }
}
