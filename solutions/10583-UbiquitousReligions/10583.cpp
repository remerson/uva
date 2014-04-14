#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

const size_t N_MAX = 32;

class union_find
{
public:

  union_find(const size_t sz) 
    : n(sz), id(new int[n])
  { 
    for(size_t i = 0; i < n; ++i) 
      id[i] = i;
  }
    
  ~union_find() { delete[] id; }

  inline bool find(int a, int b)
  {
    return root(a) == root(b);
  }

  inline void unite(int a, int b)
  {
    const int x = root(a);
    const int y = root(b);
    id[x] = y;
  }

  inline int count() const
  {
    int c = 0;
    for(size_t i = 0; i < n; ++i) 
      if(id[i] == static_cast<int>(i)) ++c;
    return c;
  }

  inline void dump() const
  {
    for(size_t i = 0; i < n; ++i) 
      printf("id[%d] = %d\n", i, id[i]);
  }

private:

  inline int root(int a)
  {
    while(a != id[a])
    {
      id[a] = id[id[a]];
      a = id[a];
    }
    return a;
  }

  size_t n;
  int *id;
};

int main()
{
  int n, m, t = 0;

  while(scanf("%d %d", &n, &m))
  {
    if(n == 0 && m == 0) break;

    union_find groups(n);

    for(int i = 0; i < m; ++i)
    {
      int i, j;
      if(scanf("%d %d", &i, &j));
      groups.unite(i-1, j-1);
    }

    printf("Case %d: %d\n", ++t, groups.count());
  }

  return 0;
}
