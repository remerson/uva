#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <bitset>
#include <list>
#include <iterator>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t MAX_RC = 128 * 128;


int main()
{
  int r, c, n;
  int test = 0;

  while(scanf("%d %d %d", &r, &c, &n))
  {
    if(r == 0 && c == 0 && n == 0) break;

    bitset<MAX_RC> rows;
    bitset<MAX_RC> cols;

    for(int i = 0; i < n; ++i)
    {
      int i, j;
      if(scanf("%d %d", &i, &j))
      {
        rows[i] = true;
        cols[j] = true;
        DEBUG(printf("Set rows[%d] cols[%d]\n", i, j));
      }
    }

    int a, b;
    if(scanf("%d %d", &a, &b));

    DEBUG(printf("ARIF %d %d\n", a, b));

    bool move = false;

    for(size_t i = max(0, a - 1); i <= min(r - 1, a + 1) && !move; ++i)
    {
      DEBUG(printf("ROW_SCAN Test rows[%d] = %c cols[%d] = %c\n", i, rows[i] ? 't' : 'f', b, cols[b] ? 't' : 'f'));
      if(rows[i] == false && cols[b] == false) move = true;
    }

    for(size_t j = max(0, b - 1); j <= min(c - 1, b + 1) && !move; ++j)
    {
      DEBUG(printf("COL_SCAN Test rows[%d] = %c cols[%d] = %c\n", a, rows[a] ? 't' : 'f', j, cols[j] ? 't' : 'f'));
      if(rows[a] == false && cols[j] == false) move = true;
    }
          
    if(move)
      printf("Case %d: Escaped again! More 2D grid problems!\n", ++test);
    else
      printf("Case %d: Party time! Let's find a restaurant!\n", ++test);
  }
  

  return 0;
}
