//#include <cstdio>
#include <cstring>
//#include <cstdlib>
//#include <cmath>

//#include <algorithm>
//#include <set>
//#include <map>
//#include <queue>
//#include <iostream>
//#include <iterator>
#include <bitset>

#include <unistd.h>

#ifndef ONLINE_JUDGE
#include <cstdio>
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Cut and paste everything from below here
//
          //#include <unistd.h>

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
      //std::ios_base::sync_with_stdio(false);
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

const int SQRT_N = 1141;
const int MAX_N = SQRT_N * SQRT_N;
const int HALF_N = MAX_N / 2;

// Odd only
bitset<HALF_N> is_prime;

void sieve()
{
  is_prime.flip();

  for(int n = 3; n < SQRT_N; n += 2)
    if(is_prime[n>>1])
    {
      //const int shift = (n<<1);
      for(int j = n * n; j < MAX_N; j += (n<<1))
        is_prime[j>>1] = false;
    }
  is_prime[0] = false;
}

const int MAX_VAL = 120;

char values[MAX_VAL / 2][4];
int length[MAX_VAL / 2] = {0};

const int MAX_BUFF = 1024 * 1024;

char output[MAX_BUFF];
char *out = &output[0];
int out_len = 0;

int main()
{
  sieve();

  // Fill in values

  // Single digit
  for(int i = 0; i < 10; i += 2)
  {
    values[i>>1][0] = '0' + i;
    values[i>>1][1] = '\n';
    length[i>>1] = 2;
  }

  // Double digit
  for(int i = 1; i < 10; ++i)
    for(int j = 0; j < 10; j += 2)
    {
      int index = ((i * 10) + j)>>1;

      values[index][0] = '0' + i;
      values[index][1] = '0' + j;    
      values[index][2] = '\n';
      length[index] = 3;
    }

  // Triple digit
  for(int i = 0; i < 2; ++i)
    for(int j = 0; j < 10; j += 2)
    {
      int index = (100 + ((i * 10) + j))>>1;

      values[index][0] = '1';
      values[index][1] = '0' + i;
      values[index][2] = '0' + j;    
      values[index][3] = '\n';
      length[index] = 4;
    }
  
  buffered_read input;

  while(true)
  {
    int n;

    input.read_unsigned(n);

    if(n == 0)
      break;

    DEBUG(printf("N = %d\n", n));

    if((n&1 && is_prime[n>>1]) || n == 2)
    {
      //write(1, "0\n", 2);
      //printf("0\n");
      memcpy(out + out_len, &values[0][0], length[0]);
      out_len += length[0];
    }
    else
    {
      int u = n;
      int v = n;

      if(!(u&1))
      {
        --u;
        ++v;
      }

      DEBUG(printf("1) U = %d V = %d\n", u, v));

      while(!is_prime[u>>1])
        u -= 2;

      DEBUG(printf("2) U = %d V = %d\n", u, v));

      while(!is_prime[v>>1])
        v += 2;

      DEBUG(printf("3) U = %d V = %d\n", u, v));

      //printf("%d\n", v - u);

      const int index = (v - u)>>1;

      DEBUG(printf("diff = %d index = %d length = %d\n", v - u, index, length[index]));

      memcpy(out + out_len, &values[index][0], length[index]);
      out_len += length[index];
    }
    
  }

  write(1, output, out_len);

  return 0;
}
