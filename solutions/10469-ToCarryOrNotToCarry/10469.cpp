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

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

typedef bitset<32> number;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  unsigned a, b;

  DEBUG(printf("foo\n"));

  while(scanf("%u %u\n", &a, &b) == 2)
  {
    DEBUG(printf("a = %u b = %u\n", a, b));

    printf("%u\n", a ^ b);
  }

  return 0;
}
