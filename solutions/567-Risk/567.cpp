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
    template<typename NUM> bool read_signed(NUM &v)
    { 
      bool negative = false;
      v = 0;

      // "fast" path - "far" from end of block
      if(size_ > 32)
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
    template<typename NUM> bool read_unsigned(NUM &v)
    { 
      v = 0;

      // "fast" path
      if(size_ > 32)
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

    bool end_reached() const
    {
      return size_ == 0;
    }

  private:
    
    void advance()
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

    void read_block()
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

const unsigned short C_MAX = 20;
const unsigned short P_MAX = 1 << 14;

unsigned short adj[C_MAX + 1][C_MAX + 1];

void dump()
{
   for(unsigned short i = 1; i <= C_MAX; ++i)
   {
     printf("%d:", i);
      for(unsigned short j = 1; j <= C_MAX; ++j)
        DEBUG(printf(" %d", adj[i][j]));
      printf("\n");
   }

}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  // buffered_read input;
  int t = 0;

  //while(!input.end_reached())
  while(true)
  {
    for(unsigned short i = 1; i <= C_MAX; ++i)
    {
      for(unsigned short j = 1; j <= C_MAX; ++j)
        adj[i][j] = P_MAX;
      adj[i][i] = 0;
    }

    for(unsigned short i = 1; i < C_MAX; ++i)
    {
      unsigned short v, j;
      //  if(!input.read_unsigned(v))
      //  break;
      if(scanf("%hu", &v) == EOF)
        break;

      DEBUG(printf("i = %d v = %d\n", i, v));

      for(unsigned short k = 0; k < v; ++k)
      {
        //input.read_unsigned(j);
        if(scanf("%hu", &j) == EOF)
          break;

        DEBUG(printf("Set adj[%d][%d] = 1\n", i, j));
        adj[i][j] = 1;
        adj[j][i] = 1;
      }
    }

    DEBUG(dump());
      
    // FW
    for(unsigned short k = 1; k <= C_MAX; ++k)
      for(unsigned short i = 1; i <= C_MAX; ++i)
        for(unsigned short j = 1; j <= C_MAX; ++j)
          adj[i][j] = min(adj[i][j], static_cast<unsigned short>(adj[i][k] + adj[k][j]));

    
    DEBUG(dump());

    // Query
    unsigned short n;

    //if(!input.read_unsigned(n))
    //  break;
    if(scanf("%hu", &n) == EOF)
      break;

    printf("Test Set #%d\n", ++t);
    DEBUG(printf("N = %d\n", n));

    for(unsigned short m = 0; m < n; ++m)
    {
      unsigned short a, b;

      //      input.read_unsigned(a);
      //input.read_unsigned(b);
      if(scanf("%hu %hu", &a, &b));      
      printf("%2d to %2d: %d\n", a, b, adj[a][b]);
    }

    putchar('\n');
    //printf("\n");
    
  }

  return 0;
}
