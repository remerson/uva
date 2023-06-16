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

const size_t MAX_NUM = 10;

void dump_histo(unsigned short *v)
{
  for(int i = 0; i < MAX_NUM; ++i)
    DEBUG(printf("v[%d] = %d\n", i, v[i]));
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  buffered_read input;
  
  while(!input.end_reached())
  {
    unsigned short n, m;
    
    input.read_unsigned(n);
    input.read_unsigned(m);

    if(n == 0 && m == 0)
      break;

    const size_t MAX_NUM = 10;

    unsigned short f1[MAX_NUM] = {0};
    
    unsigned short k;

    for(int i = 0; i < n; ++i)
    {
      input.read_unsigned(k);
      for(int j = 2; j <= k; ++j)
      {
	switch(j)
	{
	case 2:
	  ++f1[2];
	  break;
	case 3:
	  ++f1[3];
	  break;
	case 4:
	  f1[2] += 2;
	  break;
	case 5:
	  ++f1[5];
	  break;
	case 6:
	  ++f1[2];
	  ++f1[3];
	  break;
	case 7:
	  ++f1[7];
	  break;
	case 8:
	  f1[2] += 3;
	  break;
	case 9:
	  f1[3] += 2;
	  break;
	}
      }
    }

    DEBUG("HISTO1\n");
    DEBUG(dump_histo(&f1[0]));

    unsigned short f2[MAX_NUM] = {0};

    for(int i = 0; i < m; ++i)
    {
      input.read_unsigned(k);
      for(int j = 2; j <= k; ++j)
      {
	switch(j)
	{
	case 2:
	  ++f2[2];
	  break;
	case 3:
	  ++f2[3];
	  break;
	case 4:
	  f2[2] += 2;
	  break;
	case 5:
	  ++f2[5];
	  break;
	case 6:
	  ++f2[2];
	  ++f2[3];
	  break;
	case 7:
	  ++f2[7];
	  break;
	case 8:
	  f2[2] += 3;
	  break;
	case 9:
	  f2[3] += 2;
	  break;
	}
      }
    }

    DEBUG("HISTO2\n");
    DEBUG(dump_histo(&f2[0]));

    bool match {true};

    for(unsigned i = 2; i < MAX_NUM && match; i++)
      match = (f1[i] == f2[i]);

    if(match)
      printf("YES\n");
    else
      printf("NO\n");
    
  }

  return 0;
}
