#include <algorithm>

using namespace std;

typedef unsigned long long ull;

// Writes digits of the number n in digits.
template <typename T, typename OutputIterator>
OutputIterator get_digits(T n, OutputIterator digits) {
  OutputIterator pos = digits;
  while (n) {
    *pos++ = n%10;
    n /= 10;
  }
  reverse(digits, pos);
  return pos;
}

template <typename T, typename InputIterator>
T digits_to_number(InputIterator first, InputIterator last) {
  T r = 0;
  for ( ;first!=last; first++)
    r = r * 10 + *first;
  return r;
}
