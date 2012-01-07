#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers(10000, 0);
  vector<int>::iterator it;
  int n, q, query;
  int i, t=1;
  scanf("%d %d", &n, &q);
  while (n || q) {
    printf("CASE# %d:\n",t++);
    numbers.resize(n);
    for(i=0; i<n; i++) scanf("%d", &numbers[i]);
    sort(numbers.begin(), numbers.end());
    for(i=0; i<q; i++) {
      scanf("%d", &query);
      it = lower_bound(numbers.begin(), numbers.end(), query);
      if (it != numbers.end() && *it == query) {
        printf("%d found at %d\n", query, int(it - numbers.begin()) + 1);
      } else {
        printf("%d not found\n", query);
      }
    }
    scanf("%d %d",&n,&q);
  }
  return 0;
}
