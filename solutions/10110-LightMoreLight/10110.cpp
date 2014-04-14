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

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  unsigned n;

  while(scanf("%u", &n))
  {
    if(n == 0)
      break;

    const unsigned a = static_cast<int>(floor(sqrt(n)));
    const unsigned b = a * a;

    if(b == n)
      printf("yes\n");
    else
      printf("no\n");
  }
  
  return 0;
}
