#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <string>
#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int N_MAX = 32;

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

int hash[N_MAX];
int next_value = 0;

inline size_t to_node(const char a)
{
  const int index = static_cast<size_t>(a - 65);
  DEBUG(printf("hash[%c] = %d index = %d\n", a, hash[index], index));
  // No entry yet - add
  if(hash[index] == -1)
  {
    hash[index] = next_value++;
    DEBUG(printf("ADD HASH %c -> %d\n", a, hash[index]));
  }
  
  return hash[index];
}

int main()
{
  int n;

  while(scanf("%d\n", &n) == 1)
  {
    DEBUG(printf("N = %d\n", n));

    int m;

    // Reset
    next_value = 0;
    for(int i = 0; i < N_MAX; ++i)
      hash[i] = -1;

    if(scanf("%d\n", &m));

    DEBUG(printf("M = %d\n", m));

    //union_find active(n);
    bitset<N_MAX> active;
    bool connected[N_MAX][N_MAX] = {0};

    char a, b, c;

    if(scanf("%c%c%c\n", &a, &b, &c));
    DEBUG(printf("AWAKE %c%c%c\n", a, b, c));
    
//     active.unite(a_node, b_node);
//     active.unite(b_node, c_node);

    active.set(to_node(a));
    active.set(to_node(b));
    active.set(to_node(c));

    for(int i = 0; i < m; ++i)
    {
      if(scanf("%c%c\n", &a, &b));
      DEBUG(printf("CHECK %c%c\n", a, b));

      const size_t a_node = to_node(a);
      const size_t b_node = to_node(b);

      // Symmetric / undirected
      connected[a_node][b_node] = true;
      connected[b_node][a_node] = true;
    }

    bool awake = (active.count() == n);

    bitset<N_MAX> update_active = active;

    int years = 0;

    while(!awake)
    {
      awake = true;

      DEBUG(printf("NEXT PASS!\n"));

      for(int i = 0; i < n; ++i)
      { 
        DEBUG(printf("CHECK node %d active? %s\n", i, active[i] ? "yes" : "no"));

        if(!active[i])
        {
          size_t active_count = 0;
          
          for(int j = 0; j < n; ++j)
            if(active[j] && connected[i][j])
            {
              DEBUG(printf("JOINED %d %d and active[%d] = %s.\n", i, j, j, active[j] ? "yes" : "no"));
              ++active_count;
            }

          DEBUG(printf("node %d is connected to %d other active nodes.\n", i, active_count));
          
          if(active_count >= 3)
          {
            update_active.set(i);
            awake = false;
            DEBUG(printf("AWAKEN node %d\n", i));
          }
        }
      }

      active = update_active;
      if(!awake)
        ++years;
    }

    if(active.count() != n)
      printf("THIS BRAIN NEVER WAKES UP\n");
    else
      printf("WAKE UP IN, %d, YEARS\n", years);
  }

  return 0;
}
