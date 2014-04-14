#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#define DEBUG_INPUT(X)
#else
#define DEBUG(X)
#define DEBUG_INPUT(X)
#endif

using namespace std;

const unsigned MAX_N = 512;

namespace
{
  // This is sized for a total buffer size of 1Mb
  const size_t BLOCK_SIZE_BYTES = 512 * 4096;
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

      DEBUG_INPUT(printf("size_ = %d v = %d\n", size_, v));

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

      DEBUG_INPUT(printf("size_ = %d v = %d\n", size_, v));

      return !end_reached();
    }

    inline bool end_reached() const
    {
      return size_ == 0;
    }

  private:
    
    inline void advance()
    {
      DEBUG_INPUT(printf("advance (pre) size_ = %d current = [%c]\n", size_, *current_));
      --size_;
      if(size_ == 0)
      {
        read_block();
      }
      else
      {
        ++current_;
      }
      DEBUG_INPUT(printf("advance (post) size_ = %d current = [%c]\n", size_, *current_));
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
      DEBUG_INPUT(printf("READ BLOCK size = %d\n", size_));
      ++index_;
      index_ = index_ % NUM_BLOCKS;
      DEBUG_INPUT(printf("next index = %d\n", index_));
    }

    // Remaining bytes left in current block
    size_t size_;
    size_t index_;
    char *current_;
    char blocks_[NUM_BLOCKS][BLOCK_SIZE_BYTES];
    bool negative_;
  };

} // namespace

class union_find
{
public:

  // Create a new union-find/disjoint-sets of size n
  union_find(const size_t n) 
    : n_(n), parent_(new size_t[n])
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

  // Returns the size of the largest set
  inline size_t max_cardinality() const
  {
    short bins[MAX_N] = {0};

    for(size_t i = 0; i < n_; ++i)
    {
      const size_t x = root(i);
      ++bins[x];
      DEBUG(printf("  bins[%d] = %d\n", x, bins[x]));
    }
    
    short m = bins[0];

    for(size_t i = 1; i < n_; ++i)
    {
      if(bins[i] > m)
        m = bins[i];
    }
    return m;
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

  inline size_t root(size_t x) const
  {
    size_t a = x;
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

const unsigned MAX_M = 1024 * 1024;

unsigned short from[MAX_M];
unsigned short to[MAX_M];

int main()
{
  int n, m;
  int i, j, k;
  input inp;

  int p; // largest ppa

  unsigned short a, b;
  int c;

  while(inp.read_number(n) && inp.read_number(m))
  {
    DEBUG(printf("N = %d M = %d\n", n, m));

    if(n == 0 || m == 0)
      break;
    
    k = 0;
    inp.read_short(from[k]);
    inp.read_short(to[k]);
    inp.read_number(p);
    ++k;

    DEBUG(printf("START P = %d\n", p));

    for(i = 1; i < m; ++i)
    {
      inp.read_short(a);
      inp.read_short(b);
      inp.read_number(c);

      DEBUG(printf("CHECK C = %d P = %d\n", c, p));

      if(c < p)
        continue;

      if(c > p) 
      {
        k = 0;
        p = c;
      }
      from[k] = a;
      to[k] = b;
      ++k;
    }  
    
    DEBUG(printf("P = %d K = %d\n", p, k));

    disjoint_sets cities(n+1);

    for(j = 0; j < k; ++j)
    {
      cities.unite(from[j], to[j]);
    }
    
    printf("%d\n", cities.max_cardinality());
  }

  return 0;
}
