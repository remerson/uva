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
    template<typename NUM> bool read_unsigned(NUM &v)
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


const int MAX_N = 16;

const int TOO_LARGE = 1 << 28;

int adj[MAX_N][MAX_N];
int path[MAX_N][MAX_N];


void dump(int unsigned short n)
{
  for(int i = 1; i <= n; ++i)
  {
    printf("%d:", i);
    for(int j = 1; j <= n; ++j)
      printf(" %d", adj[i][j]);
    printf("\n");
  }
}

void dump_path(int unsigned short n)
{
  for(int i = 1; i <= n; ++i)
  {
    printf("%d:", i);
    for(int j = 1; j <= n; ++j)
      printf(" %d", path[i][j]);
    printf("\n");
  }
}

void write_path(int i, int j)
{
  if(i == j)
    printf(" %d", i);
  else if(path[i][j] == 0)
    return;
  else
  {
    write_path(i, path[i][j]);
    printf(" %d", j);
  }
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  buffered_read input;

  int n;
  unsigned t = 0;

  while(input.read_signed(n))
  {
    DEBUG(printf("N = %d\n", n));
    if(n == 0)
      break;

    for(int i = 1; i <= n; ++i)
    {
      for(int j = 1; j <= n; ++j)
      {
        adj[i][j] = TOO_LARGE;
        path[i][j] = 0;
      }
      adj[i][i] = 0;
    }

    for(int i = 1; i <= n; ++i)
    {
      int m, j, v;
      input.read_signed(m);
      for(int k = 0; k < m; ++k)
      {
        input.read_signed(j);
        input.read_signed(v);
        adj[i][j] = v;
        path[i][j] = i;
      }      
    }

    DEBUG(dump(n));

    int start, end;

    input.read_signed(start);
    input.read_signed(end);

    DEBUG(printf("start = %d end = %d\n", start, end));

    // Classic
    for(int k = 1; k <= n; ++k)
      for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
          const int m = adj[i][k] + adj[k][j];
          if(m < adj[i][j])
          {
            adj[i][j] = m;
            path[i][j] = path[k][j];
          }
        }

    DEBUG(dump(n));
    DEBUG(dump_path(n));

    printf("Case %d: Path =",++t);
    if(start == end)
      printf(" %d", start);
    write_path(start, end);
    printf("; %d second delay\n", adj[start][end]);
  }

  return 0;
}
