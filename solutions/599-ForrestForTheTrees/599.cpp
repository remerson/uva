#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <string>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

class union_find
{
public:

  // Create a new union-find/disjoint-sets of size n
  union_find(const size_t n) 
    : n_(n), parent_(new size_t[n_]), count_(new size_t[n_])
  { 
    for(size_t i = 0; i < n_; ++i) 
    {
      parent_[i] = i;
      count_[i] = 1;
    }
  }
    
  ~union_find() { delete[] parent_; }

  // Returns true iff a and b are part of the same set
  inline bool joined(size_t a, size_t b) const
  {
    return root(a) == root(b);
  }

  // Make a and b part of the same set.
  inline void unite(size_t a, size_t b)
  {
    const size_t x = root(a);
    const size_t y = root(b);
    DEBUG(printf("UNITE a = %d b = %d x = %d y = %d\n", a, b, x, y));
    parent_[x] = y;
    if(x != y) 
    {
      count_[y] += count_[x];
      count_[x] = count_[y];
    }
  }

  // Returns number of distinct sets
  inline size_t distinct() const
  {
    size_t c = 0;
    for(size_t i = 0; i < n_; ++i) 
      if(parent_[i] == static_cast<size_t>(i)) ++c;
    return c;
  }

  //
  inline size_t parent(size_t a) const
  {
    return root(a);
  }

  // Returns number of elements in set with parent i
  inline size_t count(size_t i) const
  {
    return count_[i];
  }

  // Returns size of union-find
  inline size_t size() const
  {
    return n_;
  }

  // Debug
  inline void dump() const
  {
    for(size_t i = 0; i < n_; ++i) 
      printf("parent_[%d] = %d\n", i, parent_[i]);

    for(size_t i = 0; i < n_; ++i) 
      printf("count_[%d] = %d\n", i, count_[i]);
  }

private:

  // Path compress a
  inline size_t root(size_t a) const
  {
    while(a != parent_[a])
    {
      parent_[a] = parent_[parent_[a]];
      a = parent_[a];
    }
    return a;
  }

  size_t n_;
  mutable size_t *parent_;
  size_t *count_;
};

inline int to_index(const char x)
{
  return x - 64;
}

const int N_MAX = 32;

const int B_MAX = 4096;

int main()
{
  std::ios_base::sync_with_stdio(false);

  int n;

  if(scanf("%d\n", &n));

  for(int t = 0; t < n; ++t)
  {
    char buffer[B_MAX + 1];

    union_find vertices(N_MAX);

    fgets(buffer, B_MAX, stdin);

    char a, b;

    while(buffer[0] != '*')
    {
      //      sscanf(buffer, "(%c,%c)", &a, &b);
      a = buffer[1];
      b = buffer[3];

      vertices.unite(to_index(a), to_index(b));

      fgets(buffer, B_MAX, stdin);
    }

    fgets(buffer, B_MAX, stdin);

    char *c = &buffer[0];

    int acorns = 0;
    int trees = 0;

    bool roots[N_MAX] = {0};

    while(*c != '\n')
    {
      if(vertices.count(to_index(*c)) == 1)
        ++acorns;
      else
        if(!roots[vertices.parent(to_index(*c))])
        {
          roots[vertices.parent(to_index(*c))] = true;
          ++trees;
        }

      ++c;
      if(*c == ',') ++c;
    }
    
    printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
  }

  return 0;
}
