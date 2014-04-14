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
  int t;

  if(scanf("%d\n", &t));
  
  DEBUG(printf("T = %d\n", t));

  for(int q = 0; q < t; ++q)
  {
    char buffer[8];
    
    fgets(buffer, 7, stdin);
    const int n = buffer[0] - 64;

    DEBUG(printf("START q = %d c = %c (%d) n = %d\n", q, buffer[0], buffer[0], n));

    union_find groups(n);

    while(true)
    {
      if(!fgets(buffer, 7, stdin)) break;
      DEBUG(printf("buffer [%s]\n", buffer));
      if(buffer[0] == '\n') break;
      DEBUG(printf("READ [%c] [%c]\n", buffer[0], buffer[1]));
      groups.unite(buffer[0] - 65, buffer[1] - 65);
      DEBUG(groups.dump());
    }

    if(q > 0) printf("\n");
    printf("%d\n", groups.count());
   
  }
    

  return 0;
}
