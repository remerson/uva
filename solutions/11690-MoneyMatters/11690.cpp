#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <string>
#include <bitset>
#include <cstring>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int N_MAX = 128 * 128;
const int M_MAX = 4 * N_MAX;

static int allzero[N_MAX] = {0};

const int B_MAX = 64;

char buffer[B_MAX];

inline char *read_int(int &v, char *b)
{ 
  bool negative = false;
  v = 0;
  while(!isdigit(*b))
  {
    if(*b == '-')
      negative = true;
    ++b;
  }
  
  while(isdigit(*b)) 
    v = v * 10 + *(b++) - '0';
  if(negative) v *= -1;
  return b;
}

inline char *read_short(short &v, char *b)
{ 
  bool negative = false;
  v = 0;
  while(!isdigit(*b))
  {
    if(*b == '-')
      negative = true;
    ++b;
  }
  
  while(isdigit(*b)) 
    v = v * 10 + *(b++) - '0';
  if(negative) v *= -1;
  return b;
}


class union_find
{
public:

  // Create a new union-find/disjoint-sets of size n
  union_find(const size_t n) 
    : n_(n), sets_(n), parent_(new size_t[n_]), count_(new size_t[n_])
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
    DEBUG(printf(" UNITE a = %d b = %d x = %d y = %d\n", a, b, x, y));
    parent_[x] = y;
    if(x != y) 
    {
      count_[y] += count_[x];
      count_[x] = count_[y];
      sets_--;
    }
  }

  // Returns number of distinct sets
  inline size_t distinct() const
  {
    // size_t c = 0;
    // for(size_t i = 0; i < n_; ++i) 
    //   if(parent_[i] == static_cast<size_t>(i)) ++c;
    // return c;
    return sets_;
  }

  //
  inline size_t parent(size_t a) const
  {
    DEBUG(printf(" PARENT %d -> %d\n", a, root(a)));
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
  size_t sets_;
  mutable size_t *parent_;
  size_t *count_;
};

int main()
{
  int t;

  if(scanf("%d\n", &t));

  DEBUG(printf("T = %d\n", t));

  for(int q = 0; q < t; ++q)
  {
    int n, m;

    if(scanf("%d %d\n", &n, &m));

    DEBUG(printf("N = %d M = %d\n", n, m));

    union_find friends(n);

    short amounts[N_MAX];

    int v;

    for(int i = 0; i < n; ++i)
    {
      //char *b = fgets(buffer, B_MAX - 1, stdin);
      char *b = gets(buffer);
      b = read_short(amounts[i], b);
      DEBUG(printf("amounts[%d] = %d\n", i, amounts[i]));
    }

    int x, y;

    for(int i = 0; i < m; ++i)
    {
      //char *b = fgets(buffer, B_MAX - 1, stdin);
      char *b = gets(buffer);
      b = read_int(x, b);
      b = read_int(y, b);

      friends.unite(x, y);
    }

    int tally[N_MAX];

    const size_t distinct = friends.distinct();
    size_t remap = 0;

    int hash[N_MAX];

    memcpy(tally, allzero, distinct * sizeof(int));

    for(size_t i = 0; i < distinct; ++i)
      hash[i] = -1;

    // If distinct sets is constant time (it is not right now)
    // then use hash trick to reduce upper bound on these next
    // two loops - i.e. bin distinct sets in as count/check amounts
    // for only distinct sets.

    for(int i = 0; i < n; ++i)
    {
      if(hash[friends.parent(i)] == -1)
        hash[friends.parent(i)] = remap++;

      tally[hash[friends.parent(i)]] += amounts[i];
    }

    bool possible = true;
    
    for(int i = 0; i < distinct && possible; ++i)
      possible = (tally[hash[i]] == 0);

    if(possible)
      write(1, "POSSIBLE\n", 9);
    else
      write(1, "IMPOSSIBLE\n", 11);

  }

  return 0;
}
