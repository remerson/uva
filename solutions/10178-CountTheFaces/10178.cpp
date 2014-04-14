#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <string>
#include <bitset>
#include <cassert>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#define NDEBUG
#else
#define DEBUG(X)
#endif

class union_find
{
public:

  // Create a new union-find/disjoint-sets of size n
  union_find(const size_t n) 
    : n_(n), parent_(new size_t[n_])
  { 
    for(size_t i = 0; i < n_; ++i) 
      parent_[i] = i;
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
    DEBUG(printf(" UNITE a = %d b = %d x = %d y = %d\n", a, b, x, y));
    parent_[x] = y;
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
    DEBUG(printf(" PARENT %d -> %d\n", a, root(a)));
    return root(a);
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
};

typedef union_find disjoint_sets;

  // Remaps a non-contiguous but finite set of cardinality n
  // onto a contiguous range <= n (possibly << n)
  class remap
  {
  public:

    explicit remap(unsigned n)
      : next_(0), map_(new int[n])
#ifndef ONLINE_JUDGE
      , n_(n)
#endif
    {
      DEBUG(printf("REMAP n = %d\n", n));
      for(size_t i = 0; i < n; ++i)
        map_[i] = -1;
    }

    // Do not inherit
    ~remap()
    {
      delete[] map_;
    }

    inline int get_index(int x) const
    {
      DEBUG(assert(x >= 0));
      DEBUG(assert(x < n_));
      if(map_[x] == -1)
      {
        DEBUG(printf("ADD map_[%d] = %d\n", x, next_));
        map_[x] = next_++;
        DEBUG(assert(next_ <= n_));
      }
      DEBUG(assert(map_[x] < next_));
      return map_[x];
    }

    // Returns the upper bound of the contiguous range
    inline unsigned upper_bound() const
    {
      DEBUG(assert(next_ <= n_))
      return next_;
    }

  private:

    // Non-copyable
    remap &operator=(const remap &);
    remap(const remap &);

    mutable int next_;
    mutable int *map_;
#ifndef ONLINE_JUDGE
    const unsigned n_;
#endif
  };


int main(int argc, char **argv)
{
  int n, e;

  while(scanf("%d %d\n", &n, &e) == 2)
  {
    DEBUG(printf("N = %d E = %d\n", n, e));

    disjoint_sets connected(n);

    remap hash(255);

    char buffer[64];

    for(int i = 0; i < e; ++i)
    {
      fgets(buffer, 63, stdin);
      DEBUG(printf("BUFFER [%s]\n", buffer));
      connected.unite(hash.get_index(buffer[0]), hash.get_index(buffer[2]));
    }

    printf("%d\n", connected.distinct() - n + e + 1);
  }

  return 0;
}
