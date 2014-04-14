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

const int B_MAX = 128;
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
    DEBUG(printf(" UNITE a = %d b = %d x = %d y = %d\n", a, b, x, y));
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

#define ENEMY(X) (n + X)

int main()
{
  int n;

  if(scanf("%d\n", &n));

  union_find people(2 * n);

  int op, a, b;

  //char buffer[B_MAX + 1];

  //while(scanf("%d %d %d\n", &op, &a, &b) == 3)
  while(char *buf = fgets(buffer, B_MAX, stdin))
  {
    buf = read_int(op, buf);
    buf = read_int(a, buf);
    buf = read_int(b, buf);
    

    if(op == 0 && a == 0 && b == 0) break;

    switch(op)
    {
    case 1: // setFriends
      {
        DEBUG(printf("SET FRIENDS %d %d\n", a, b));

        if(people.joined(a, ENEMY(b)))
          //printf("-1\n");
          write(1, "-1\n", 3);
        else
        {
          people.unite(a, b);
          people.unite(ENEMY(a), ENEMY(b));
        }
      }
      break;
    case 2: // setEnemies
      {
        DEBUG(printf("SET ENEMIES %d %d\n", a, b));

        if(people.joined(a, b))
          //printf("-1\n");
          write(1, "-1\n", 3);
        else
        {
          people.unite(a, ENEMY(b));
          people.unite(b, ENEMY(a));
        } 
      }
      break;
    case 3: // areFriends
      {
        DEBUG(printf("QUERY: FRIENDS %d %d\n", a, b));
        if(people.joined(a, b))
          //printf("1\n");
          write(1, "1\n", 2);
        else
          //printf("0\n");
          write(1, "0\n", 2);
      }
      break;
    case 4: // areEnemies
      {
        DEBUG(printf("QUERY: ENEMIES %d %d\n", a, b));
        if(people.joined(a, ENEMY(b)))
          //printf("1\n");
          write(1, "1\n", 2);
        else
          //printf("0\n");
          write(1, "0\n", 2);
      }
      break;
    }

    //    people.dump();
  }

  return 0;
}
