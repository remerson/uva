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

const int N_MAX = 1024 * 128;

int main()
{
  unsigned t;

  cin >> t;
  
  for(unsigned q = 0; q < t; ++q)
  {
    unsigned f;
    cin >> f;

    size_t n = 0;
    typedef std::map<std::string, size_t> NameMap;
    NameMap names;
    union_find all(N_MAX);

    for(unsigned i = 0; i < f; ++i)
    {
      std::string name1, name2;

      cin >> name1;
      cin >> name2;

      NameMap::const_iterator it1 = names.find(name1);
      if(it1 == names.end())
        it1 = names.insert(NameMap::value_type(name1, n++)).first;
      
      NameMap::const_iterator it2 = names.find(name2);
      if(it2 == names.end())
        it2 = names.insert(NameMap::value_type(name2, n++)).first;

      all.unite(it1->second, it2->second);

      DEBUG(printf("n = %d (%d) parent = %d\n", it1->second, it2->second, all.parent(it1->second)));

      printf("%d\n", all.count(all.parent(it1->second)));
    }
  }

  return 0;
}
