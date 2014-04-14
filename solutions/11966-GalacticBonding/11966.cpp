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

////////////////////////////////////////////////////////////

// Enables set cardinality logic. This consumes some small
// overhead and doubles memory size, so only enable if 
// you really need it.
//#define DISJOINT_SETS_SUPPORT_CARDINALITY

#ifndef ONLINE_JUDGE
#include <iostream>
using std::cout;
using std::endl;
#endif

template<typename ELEMENT> class disjoint_sets_base
{
public:

  // Create a new disjoint sets of n elements.
  explicit disjoint_sets_base(ELEMENT n) 
    : n_(n), 
      parent_(new ELEMENT[n_])
#ifdef DISJOINT_SETS_SUPPORT_CARDINALITY
, count_(new ELEMENT[n_])
#endif
  { 
    for(ELEMENT i = 0; i < n_; ++i) 
    {
      parent_[i] = i;
#ifdef DISJOINT_SETS_SUPPORT_CARDINALITY
      count_[i] = 1;
#endif
    }
  }
    
  ~disjoint_sets_base() { delete[] parent_; }

  // Returns true iff a and b are part of the same set
  inline bool joined(ELEMENT a, ELEMENT b) const
  {
    return root(a) == root(b);
  }

  // Make a and b part of the same set.
  inline void unite(ELEMENT a, ELEMENT b)
  {
    const ELEMENT x = root(a);
    const ELEMENT y = root(b);
#ifndef ONLINE_JUDGE
    cout << " UNITE a = " << a << " b = " << b << " (root x = " << x << " y = " << y << ")" << endl;
#endif
    parent_[x] = y;
#ifdef DISJOINT_SETS_SUPPORT_CARDINALITY
    if(x != y) 
    {
      count_[y] += count_[x];
      count_[x] = count_[y];
    }
#endif
  }

  // Returns number of distinct sets: linear
  inline ELEMENT distinct() const
  {
    ELEMENT distinct = 0;
    for(ELEMENT i = 0; i < n_; ++i) 
      if(parent_[i] == i) ++distinct;
    return distinct;
  }

  // Finds the parent (set number) of element i
  inline ELEMENT find(ELEMENT i) const
  {
    const ELEMENT r = root(i);
#ifndef ONLINE_JUDGE
    cout << " PARENT " << i << " -> " << r << endl;
#endif
    return r;
  }

#ifdef DISJOINT_SETS_SUPPORT_CARDINALITY
  // Returns number of elements in set with parent i
  inline ELEMENT cardinality(ELEMENT i) const
  {
    return count_[i];
  }
#endif

  // Returns number of elements inside disjoint sets
  inline ELEMENT size() const
  {
    return n_;
  }

#ifndef ONLINE_JUDGE
  inline void dump() const
  {
    for(ELEMENT i = 0; i < n_; ++i)
      cout << "parent_[" << i << "] = " << parent_[i] << endl;

#ifdef DISJOINT_SETS_SUPPORT_CARDINALITY
    for(ELEMENT i = 0; i < n_; ++i) 
      printf("count_[%d] = %d\n", i, count_[i]);
#endif
  }
#endif

private:

  // Non-copyable
  disjoint_sets_base(const disjoint_sets_base &other);
  disjoint_sets_base &operator=(const disjoint_sets_base &other);

  // Path compress a
  inline ELEMENT root(ELEMENT a) const
  {
    while(a != parent_[a])
    {
      parent_[a] = parent_[parent_[a]];
      a = parent_[a];
    }
    return a;
  }

  const ELEMENT n_;
  mutable ELEMENT *parent_;
#ifdef DISJOINT_SETS_SUPPORT_CARDINALITY
  ELEMENT *count_;
#endif
};

typedef disjoint_sets_base<unsigned short> disjoint_sets;

////////////////////////////////////////////////////////////


using namespace std;

const unsigned N_MAX = 1024;

double x[N_MAX];
double y[N_MAX];

inline double dist(int i, int j)
{
  DEBUG(printf("DIST %d -> %d\n", i, j));
  const double xd = fabs(x[j] - x[i]);
  DEBUG(printf("xd = %lf\n", xd));
  const double x_dist = xd * xd;

  const double yd = fabs(y[i] - y[j]);
  DEBUG(printf("yd = %lf\n", yd));
  const double y_dist = yd * yd;

  const double dist = sqrt(x_dist + y_dist);

  DEBUG(printf("DIST %d -> %d = %lf\n", i, j, dist));

  return dist;
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int t;

  if(scanf("%d\n", &t));

  DEBUG(printf("T = %d\n", t));

  for(int q = 1; q <= t; ++q)
  {
    double d;
    int n;

    if(scanf("%d", &n));

    DEBUG(printf("N = %d\n", n));

    if(scanf("%lf", &d));
    
    DEBUG(printf("D = %lf\n", d));

    disjoint_sets constellations(n);

    for(int i = 0; i < n; ++i)
    {
      if(scanf("%lf %lf", &x[i], &y[i]));
      DEBUG(printf("x[%d] = %lf y[%d] = %lf\n", i, x[i], i, y[i]));

      for(int j = 0; j <= i; ++j)
      {
        if(i != j && dist(i, j) <= d)
          constellations.unite(i, j);
      }
    }

    printf("Case %d: %d\n", q, constellations.distinct());
  }

  return 0;
}
