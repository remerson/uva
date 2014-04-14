#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <bitset>
#include <set>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

inline char *read_unsigned(unsigned &v, char *b)
{
  while(!isdigit(*b)) ++b;
  v = 0;
  
  while(isdigit(*b)) 
    v = v * 10 + *(b++) - '0';
  return b;
}

const unsigned B_MAX = 1024 * 1024;

int main()
{
  typedef std::multiset<unsigned> ValueSet;
  unsigned n, k, v;
  char buffer[B_MAX];

  while(true)
  {
    char *b = fgets(buffer, B_MAX - 1, stdin);
    read_unsigned(n, b);

    DEBUG(printf("N = %u\n", n));

    if(n == 0) break;

    ValueSet values;
    long long total = 0;

    for(unsigned i = 0; i < n; ++i)
    {
      char *b = fgets(buffer, B_MAX - 1, stdin);

      b = read_unsigned(k, b);

      DEBUG(printf("K = %u\n", k));

      for(unsigned j = 0; j < k; ++j)
      {
        b = read_unsigned(v, b);
        DEBUG(printf("INSERT v = %u\n", v));
        values.insert(v);
      }

      total += *values.rbegin() - *values.begin();
      values.erase(--values.end());
      values.erase(values.begin());
    }

    printf("%lld\n", total);
  }

  return 0;
}
