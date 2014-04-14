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

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

// Page buffered (integer) read
namespace
{
  const size_t BLOCK_SIZE_BYTES = 4 * 4096;
  const size_t NUM_BLOCKS = 2;

  class input
  {
  public:

    input()
      : size_(0), index_(0), current_(0)
    {
#ifdef ONLINE_JUDGE
      std::ios_base::sync_with_stdio(false);
#endif
      read_block();
    }

    template<typename NUM> inline bool read_number(NUM &v)
    { 
      negative_ = false;
      v = 0;

      if(size_ > 16)
      {
        while(!isdigit(*current_))
        {
          if(*current_ == '-')
            negative_ = true;
          --size_;
          ++current_;
        }
        
        while(isdigit(*current_))
        {
          v = v * 10 + *current_ - '0';
          --size_;
          ++current_;
        }

        if(negative_) 
          v *= -1;

        return true;
      }
      else
      {
        while(!isdigit(*current_) && !end_reached())
        {
          if(*current_ == '-')
            negative_ = true;
          advance();
        }
        
        while(isdigit(*current_) && !end_reached())
        {
          v = v * 10 + *current_ - '0';
          advance();
        }
      }

      if(negative_) 
        v *= -1;

      //      DEBUG(printf("size_ = %d v = %d\n", size_, v));

      return !end_reached();
    }

    inline bool read_short(unsigned short &v)
    { 
      v = 0;

      // This makes (possibly unsafe) assumptions about how much non-digit space exists
      if(size_ > 8)
      {
        while(!isdigit(*current_))
        {
          --size_;
          ++current_;
        }
        
        while(isdigit(*current_))
        {
          v = v * 10 + *current_ - '0';
          --size_;
          ++current_;
        }

        return false;
      }
      else
      {
        while(!isdigit(*current_) && !end_reached())
        {
          advance();
        }
        
        while(isdigit(*current_) && !end_reached())
        {
          v = v * 10 + *current_ - '0';
          advance();
        }
      }

      //      DEBUG(printf("size_ = %d v = %d\n", size_, v));

      return !end_reached();
    }

    inline bool end_reached() const
    {
      return size_ == 0;
    }

  private:
    
    inline void advance()
    {
      //      DEBUG(printf("advance (pre) size_ = %d current = [%c]\n", size_, *current_));
      --size_;
      if(size_ == 0)
      {
        read_block();
      }
      else
      {
        ++current_;
      }
      //      DEBUG(printf("advance (post) size_ = %d current = [%c]\n", size_, *current_));
    }

    inline void read_block()
    {
      current_ = &blocks_[index_][0];
      size_ = read(0, current_, sizeof(char) * BLOCK_SIZE_BYTES);
#ifndef ONLINE_JUDGE
      char output[BLOCK_SIZE_BYTES + 1];
      strncpy(output, blocks_[index_], min(size_, BLOCK_SIZE_BYTES));
      output[size_] = '\0';
      printf("READ BLOCK [%s]\n", output);
#endif
      //      DEBUG(printf("READ BLOCK size = %d\n", size_));
      ++index_;
      index_ = index_ % NUM_BLOCKS;
      //DEBUG(printf("next index = %d\n", index_));
    }

    // Remaining bytes left in current block
    size_t size_;
    size_t index_;
    char *current_;
    char blocks_[NUM_BLOCKS][BLOCK_SIZE_BYTES];
    bool negative_;
  };

} // namespace

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


const size_t MAX_N = 10010;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int t;

  unsigned short n, m, l;

  input inp;

  inp.read_number(t);

  DEBUG(printf("T = %d\n", t));

  for(int s = 0; s < t; ++s)
  {
    inp.read_short(n);
    inp.read_short(m);
    inp.read_short(l);

    DEBUG(printf("N = %u M = %u L = %u\n", n, m, l));
    
    unsigned short a = 0, b = 0;

    vector<unsigned short> join[MAX_N];

    for(int i = 0; i < m; ++i)
    {
      inp.read_short(a);
      inp.read_short(b);
      join[a].push_back(b);
      DEBUG(printf("ADD %u -> %u (%u)\n", a, b, join[a].size()));
    }
    
    bitset<MAX_N> hit;
    
    unsigned short q[2 * MAX_N];

    q[0] = 0;

    for(int i = 0; i < l; ++i)
    {
      inp.read_short(a);
      DEBUG(printf("CHECK %u\n", a));
      q[++q[0]] = a;        
    }

    while(q[0] > 0)
    {
      const unsigned short v = q[q[0]--];

      if(hit.test(v))
        continue;
      
      hit.set(v);
      DEBUG(printf("HIT %u (%u)\n", v, join[v].size()));
      for(size_t j = 0; j < join[v].size(); ++j)
      {
        if(!hit.test(join[v].at(j)))
        {
          DEBUG(printf("Q EDGE %u\n", join[v].at(j)));
          q[++q[0]] = join[v].at(j);
        }
      }
    }

    printf("%u\n", hit.count());
  }
  

  return 0;
}
