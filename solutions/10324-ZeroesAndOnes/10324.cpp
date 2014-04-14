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

using namespace std;

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

const int MAX_L = 1024 * 1024;

int length[MAX_L];

namespace
{
  const size_t BLOCK_SIZE_BYTES = 4096;
  //const size_t BLOCK_SIZE_BYTES = 3;
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
      DEBUG_READ(printf("size_ = %d\n", size_));
      return !end_reached();
    }

    bool end_reached() const
    {
      return size_ == 0;
    }

    bool read_length()
    {
      while(*current_ != '0' && *current_ != '1')
      {
        advance();
        if(size_ == 0)
          return false;
      }

      char p = *current_;
      advance();
      if(size_ == 0)
        return false;
        
      length[0] = 0;

      int i = 1;

      while(true)
      {
        char *current = current_;

        for(int j = size_; j > 0; --j)
        {
          if(*current != '0' && *current != '1')
            break;

          if(*current == p)
          {
            length[i] = length[i-1] + 1;
            DEBUG(printf("LEN length[%d] = %d\n", i, length[i]));
          }
          else
            length[i] = 0; 
          
          ++i;
          p = *current;
          ++current;
        }

        // if(*current != '0' && *current != '1')
        // {
        //    size_ -= (current - current_);
        //    current_ = current;
        //    DEBUG(printf("read_length - terminated (not 1/0) size = %d\n", size_));
        //    break;
        // }

        if(current - current_ == size_)
        {
          DEBUG(printf("read_length - read another block\n", size_));  
          read_block();
          if(size_ == 0)
            break;
        }
        else
        {
          size_ -= (current - current_);
          current_ = current;
          DEBUG(printf("read_length - read less than block, size = %d\n", size_));
          break;
        }
      }

      DEBUG(printf("LENGTH = %d\nLENGTH = ", i));
      DEBUG(for(int y = 0; y <i; ++y) printf("%d",length[y]));
      DEBUG(printf("\n"));
      return !end_reached();
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


int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  buffered_read input;

  int n, i, j, a, b;

  int t = 0;

  while(true)
  {
    if(!input.read_length())
      break;

    if(!input.read_unsigned(n))
      break;

    printf("Case %d:\n", ++t);

    for(int k = 0; k < n; ++k)
    {
      input.read_unsigned(i);
      input.read_unsigned(j);

      if(i < j )
      {
        a = i;
        b = j;
      }
      else
      {
        a = j;
        b = i;
      }

      DEBUG(printf("a = %d length[a] = %d\n", a, length[a]));
      DEBUG(printf("b = %d length[b] = %d\n", b, length[b]));
      
      if(length[b] - length[a] == (b - a))
      {
        //write(1, "Yes\n", 4);
        printf("Yes\n");
      }
      else
      {
        printf("No\n");
        //write(1, "No\n", 3);
      }

      if(input.end_reached())
        break;
    }
    //fflush(stdout);
  }

  return 0;
}
