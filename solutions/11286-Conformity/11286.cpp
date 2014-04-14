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

const int V_MAX = 5;

struct Val
{
    int v[V_MAX];

    Val(const int values[V_MAX])
    {
      memcpy(v, values, sizeof(int) * V_MAX);
    }

    bool operator<(const Val &other) const
    {
      for(int i = 0; i < V_MAX; ++i)
      {
        if(v[i] < other.v[i]) return true;
        if(v[i] > other.v[i]) return false;
      }

      return false;
    }
};

typedef std::map<Val, int> ValueMap;

int main()
{
  std::ios_base::sync_with_stdio(false);

  int v[V_MAX];

  int n;

  while(scanf("%d", &n))
  {
    if(n == 0) break;

    ValueMap all;

    int most_pop = 0;

    for(int i = 0; i < n; ++i)
    {
      if(scanf("%d %d %d %d %d", &v[0],&v[1],&v[2],&v[3],&v[4]));
      sort(v, v + V_MAX);

      DEBUG(printf("SORTED %d %d %d %d %d\n", v[0],v[1],v[2],v[3],v[4]));

      Val val(v);
      
      ValueMap::iterator it = all.find(val);

      if(it == all.end())
      {
        DEBUG(printf("ADD new\n"));
        it = all.insert(ValueMap::value_type(val, 0)).first;
      }
      
      (it->second)++;

      most_pop = max(most_pop, it->second); 
    }

    int conformity = 0;

    ValueMap::const_iterator it = all.begin();
    const ValueMap::const_iterator ie = all.end();

    while(it != ie)
    {
      if(it->second == most_pop)
        conformity += it->second;
      ++it;
    }

    printf("%d\n", conformity);
  }

  return 0;
}
