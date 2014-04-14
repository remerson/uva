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

const size_t N_MAX = 32;

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
    if(x != y) count_[y] += count_[x];
  }

  // Returns number of distinct sets
  inline size_t distinct() const
  {
    size_t c = 0;
    for(size_t i = 0; i < n_; ++i) 
      if(parent_[i] == static_cast<size_t>(i)) ++c;
    return c;
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

//const int N_MAX = 32;

int main()
{
  int c, r;

  //while(scanf("%d %d\n", &c, &r))
  while(true)
  {
    cin >> c;
    cin >> r;
    if(c == 0 && r == 0) break;

    typedef std::map<std::string, size_t> NameMap;

    NameMap names;

    //char name[4 * N_MAX];

    for(size_t i = 0; i < (size_t) c; ++i)
    {
      //fgets(name, 4 * N_MAX - 1, stdin);
      //const size_t l = strlen(name);
      //name[l-1] = '\0';
      std::string name;
      std::cin >> name;
      DEBUG(printf("INSERT %s -> %u\n", name.c_str(), i));
      names.insert(NameMap::value_type(name, i));
    }

    union_find groups(names.size());

    for(int i = 0; i < r; ++i)
    {
      // fgets(name, 4 * N_MAX - 1, stdin);
//       const size_t l = strlen(name);
//       name[l-1] = '\0';

//       size_t j = 0;
//       while(name[j] != ' ') ++j;
//       name[j] = '\0';
//       ++j;
      
      string name1;
      string name2;

      cin >> name1;
      cin >> name2;
      
      DEBUG(printf("READ [%s] -> %u, [%s] -> %u\n", name1.c_str(), names.find(name1)->second, name2.c_str(), names.find(name2)->second));
      groups.unite(names.find(name1)->second, names.find(name2)->second);
      //DEBUG(groups.dump());
    }

    DEBUG(printf("DS %d\n", groups.distinct()));

    size_t largest = 0;
    for(size_t i = 0; i < groups.size(); ++i)
      if(groups.count(i) > largest) largest = groups.count(i);

    printf("%d\n", largest);
  }

  return 0;
}
