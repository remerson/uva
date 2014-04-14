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
    char buffer[64];
    
    fgets(buffer, 63, stdin);
    const int n = atoi(buffer) + 1;

    DEBUG(printf("START q = %d buffer [%s] n = %d\n", q, buffer, n));

    union_find groups(n);

    int success = 0, failed = 0;

    while(true)
    {
      if(!fgets(buffer, 63, stdin)) break;
      DEBUG(printf("buffer [%s]\n", buffer));
      if(buffer[0] == '\n') break;

      char command;
      int a, b;
      
      sscanf(buffer, "%c %d %d", &command, &a, &b);
      
      if(command == 'c')
        groups.unite(a, b);
      else
      {
        if(groups.find(a, b))
          ++success;
        else
          ++failed;
      }
      DEBUG(groups.dump());
    }

    if(q > 0) printf("\n");
    printf("%d,%d\n", success, failed);
   
  }
    

  return 0;
}
