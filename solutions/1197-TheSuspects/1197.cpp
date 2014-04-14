#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#define DEBUG_INPUT(X) //{ X; }
#else
#define DEBUG(X)
#define DEBUG_INPUT(X)
#endif

using namespace std;

namespace
{
  // This is sized for a total buffer size of 1Mb
  const size_t BLOCK_SIZE_BYTES = 8 * 4096;
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

    inline bool read_short(unsigned short &v)
    { 
      v = 0;

      // This makes (possibly unsafe) assumptions about how much non-digit space exists
      if(size_ > 16)
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

        return true;
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

  inline size_t cardinality(size_t a) const
  {
    size_t c = 0;

    const size_t x = root(a);

    for(size_t i = 0; i < n_; ++i)
    {  
      const size_t y = root(i);
      DEBUG(printf("x = %d y = %d\n", x, y));
      if(y == x) ++c;
    }
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

const unsigned MAX_M = 512;
const unsigned MAX_N = 64 * MAX_M;

int main()
{
  input inp;

  unsigned short n, m;
  unsigned short i, j, k, a, b;

  while(inp.read_short(n) && inp.read_short(m))
  {
    DEBUG(printf("N = %d (%d) M = %d (%d)\n", n, MAX_N, m, MAX_M));

    if(n == 0 && m == 0)
      break;

    disjoint_sets students(n);

    for(i = 0; i < m; ++i)
    {
      inp.read_short(k);
      DEBUG(printf("i = %d k = %d\n", i, k));
      if(k > 0)
      {
        inp.read_short(a);
        DEBUG(printf("a = %d\n", a));
        if(k > 1);
        for(j = 1; j < k; ++j)
        {
          inp.read_short(b);
          students.unite(a, b);
        }
      }
    }

    printf("%d\n", students.cardinality(0));
  }

  return 0;
}
