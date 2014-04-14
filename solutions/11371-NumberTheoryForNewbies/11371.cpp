#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <iterator>
#include <bitset>

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

unsigned long long order(unsigned long long n)
{
  DEBUG(printf("n = %llu\n", n));

  char buffer[32] = {0};

  char *b = &buffer[30];

  do
  {
    *b = n % 10 + '0';
    n /= 10;
    --b;
  } while(n);

  const size_t len = &buffer[30] - b;

  ++b;

  DEBUG(printf("pre-sort [%s]\n", b));

  sort(b, b + len);

  DEBUG(printf("post-sort [%s]\n", b));

  // No leading zeroes
  if(*b == '0')
  {
    for(size_t j = 0; j < len; ++j)
      if(*(b + j) != '0')
      {
        char t = *b;
        *b = *(b + j);
        *(b + j) = t;
        break;
      }
  }

  DEBUG(printf("order [%s]\n", b));

  return atoll(b);
}

unsigned long long rev(unsigned long long n)
{
  DEBUG(printf("rev %llu\n", n));

  char buffer[32] = {0};

  char *b = &buffer[0];

  do
  {
    *b = n % 10 + '0';
    n /= 10;
    ++b;

  } while(n);

  DEBUG(printf("pre-rev [%s]\n", &buffer[0]));

  sort(&buffer[0], b, std::greater<char>());

  // No leading zeroes
  if(buffer[0] == '0')
  {
    for(size_t j = 1; j < 32; ++j)
      if(buffer[j] != '0')
      {
        swap(buffer[0], buffer[j]);
        break;
      }
  }

  DEBUG(printf("zero correct [%s]\n", &buffer[0]));

  return(atoll(&buffer[0]));
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  unsigned n;

  while(scanf("%u",&n) == 1)
  {
    const unsigned long long v = order(n);

    const unsigned long long a = v;
    const unsigned long long b = rev(v);

    const unsigned long long x = max(a, b);
    const unsigned long long y = min(a, b);
    const unsigned long long d = x - y;

    printf("%llu - %llu = %llu = 9 * %llu\n", x, y, d, (d / 9));
    
  }

  return 0;
}
