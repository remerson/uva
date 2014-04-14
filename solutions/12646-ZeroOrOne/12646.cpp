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

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  char a, b, c;

  while(scanf("%c %c %c\n", &a, &b, &c) == 3)
  {
    if((a == '1' && b == '0' && c == '0')
       || (a == '0' && b == '1' && c == '1'))
      printf("A\n");
    else if((a == '0' && b == '1' && c == '0')
            || (a == '1' && b == '0' && c == '1'))
      printf("B\n");
    else if((a == '0' && b == '0' && c == '1')
            || (a == '1' && b == '1' && c == '0'))
      printf("C\n");
    else
      printf("*\n");
     
  }
  

  return 0;
}
