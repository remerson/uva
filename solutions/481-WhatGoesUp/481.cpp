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

///////////////////////////////////////////////////////////////////////////////
//
// Cut and paste everything from below here
//
#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG_READ(X) { X; }
#else
#define DEBUG_READ(X)
#endif

namespace
{
  const size_t BLOCK_SIZE_BYTES = 4096;
  const size_t NUM_BLOCKS = 2;

  //
  // Optimised integer (signed/unsigned) only read from stdin.
  //
  // This can only read integers.
  //
  // Assumes the input file only contains number characters (0-9)
  // or non-readable characters (< ASCII 47).
  //
  // Input containing ASCII values above 57 ('9') will give
  // unpredictable (bad) results. You have been warned.
  //
  // Do not mix using this with scanf/cin. It will not work.
  //
  // Copying is also probably a bad idea.
  //
  // It is intended to be instantiated once only up front in main()
  // and then used until termination.
  //

  class buffered_read
  {
  public:

    buffered_read()
      : current_(0), index_(0), size_(0)
    {
#ifdef ONLINE_JUDGE
      std::ios_base::sync_with_stdio(false);
#endif
      read_block();
    }
    
    //
    // Read a signed value into v.
    //
    // Returns a flag to indicate whether more input is available (true)
    // or not (false).
    //
    // The type NUM must support operators: =, * and +.
    // 
    // It must also support signed values and be large enough to hold
    // the value read.
    //
    template<typename NUM> inline bool read_signed(NUM &v)
    { 
      bool negative = false;
      v = 0;

      // "fast" path - "far" from end of block
      if(size_ > 16)
      {
        char *current = current_;
        const char *start = current_;

        while(*current < 48)
        {
          if(*current == '-')
            negative = true;

          ++current;
        }

        do
        {
          v = v * 10 + *current - '0';
          ++current;
        } while(*current > 47);

        if(negative)
          v *= -1;

        size_ -= (current - start);
        current_ = current;

        DEBUG_READ(printf(" -- (fast) read_signed = %d\n", v));
        return true; // must be more to read (although more carefully)
      }

      // "slow" path - near end of block
      while(*current_ < 48 && !end_reached())
      {
        if(*current_ == '-')
          negative = true;
        advance();
      }
        
      while(*current_ > 47 && !end_reached())
      {
        v = v * 10 + *current_ - '0';
        advance();
      }

      if(negative)
        v *= -1;
      
      DEBUG_READ(printf(" -- (slow) read_signed = %d\n", v));
      return !end_reached();
    }

    //
    // Read an signed value into v. Optimised to not bother looking
    // for a leading unary minus.
    //
    // Returns a flag to indicate whether more input is available (true)
    // or not (false).
    //
    // The type NUM must support operators: =, * and +.
    // 
    // It must also support unsigned values and be large enough to hold
    // the value read.
    //
    template<typename NUM> inline bool read_unsigned(NUM &v)
    { 
      v = 0;

      // "fast" path
      if(size_ > 16)
      {
        char *current = current_;
        const char *start = current_;

        while(*current < 48)
          ++current;
        
        do
        {
          v = v * 10 + *current - '0';
          ++current;
        } while(*current > 47);

        size_ -= (current - start);
        current_ = current;

        DEBUG_READ(printf(" -- (fast) read_unsigned = %u\n", v));
        return true; // must be more to read (although more carefully)
      }

      // "slow" path
      while(*current_ < 48 && !end_reached())
        advance();

      while(*current_ > 47 && !end_reached())
      {
        v = v * 10 + *current_ - '0';
        advance();
      }
      
      DEBUG_READ(printf(" -- (slow) read_unsigned = %u\n", v));
      return !end_reached();
    }

    inline bool end_reached() const
    {
      return size_ == 0;
    }

  private:
    
    inline void advance()
    {
      --size_;
      if(size_ == 0)
      {
        read_block();
      }
      else
      {
        ++current_;
      }
    }

    inline void read_block()
    {
      current_ = &blocks_[index_][0];
      size_ = read(0, current_, sizeof(char) * BLOCK_SIZE_BYTES);
      ++index_;
      index_ = (index_ % NUM_BLOCKS);
    }

    // Remaining bytes left in current block
    char *current_;
    char blocks_[NUM_BLOCKS][BLOCK_SIZE_BYTES];
    size_t index_;
    size_t size_;
  };

} // namespace

//
// End of buffered_read
//
///////////////////////////////////////////////////////////////////////////////


using namespace std;

const size_t MAX_N = 100010;

int v[MAX_N]; // values
int m[MAX_N]; // index into v of the smallest element ending LIS of length i
int p[MAX_N]; // parent information for LIS sequence

// Debug util
void dump(int n)
{
  printf("  index m[%d] =", n);
  for(int i = 1; i <= n; ++i)
    printf(" %d", m[i]);
  printf("\n");

  printf("  value m[%d] =", n);
  for(int i = 1; i <= n; ++i)
    printf(" %d", v[m[i]]);
  printf("\n");

}

void dump_lis(int len)
{
  int j = m[len];

  int s[MAX_N];

  for(int i = 0; i < len; ++i)
  {
    s[i] = v[j];
    j = p[j];
  }

  reverse(s, s + len);

  for(int i = 0; i < len; ++i)
    printf("%d\n", s[i]);
}


struct ValueCompare
{
  inline bool operator()(const int &a, const int &b) const
  {
    return v[a] < v[b];
  }
};

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  buffered_read inp;

  size_t n = 0; // count of number of values read

  while(inp.read_signed(v[n++]))
    DEBUG(printf("v[%d] = %d\n", (n - 1), v[n - 1]));
  
  --n;

  m[1] = 0;
  p[1] = 0;

  int len = 1; // length of the longest list found so far

  ValueCompare comp;

  for(size_t i = 1; i < n; ++i)
  {
    DEBUG(printf("i = %d considering v[%d] = %d m[%d] = %d\n", i, i, v[i], i, v[m[len]]));

    // New longest LIS, extend
    if(v[i] > v[m[len]])
    {
      p[i] = m[len]; // Store parent
      m[++len] = i;
      DEBUG(printf("EXTEND m[%d] = %d\n", len, v[m[len]]));
    }
    else
    {
      
      // m+1 because ignore the 0th element (this is the trival empty LIS)
      int *it = upper_bound(m + 1, m + len, i, comp);
      DEBUG(printf("CHANGE %d -> %d\n", *it, i));
      *it = i;
      p[i] = *(it - 1); // parent is previous element of the newly inserted
    }
    DEBUG(dump(len));
  }

  printf("%d\n-\n", len);

  dump_lis(len);

  return 0;
}
