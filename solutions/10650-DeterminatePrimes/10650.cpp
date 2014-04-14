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

const int SQRT_N = 190;
const int MAX_N = SQRT_N * SQRT_N;
const int HALF_N = MAX_N / 2;

// Odd only
bitset<HALF_N> is_prime;

int num_primes = 0;

// Gap between prime i and previous
int prime_gaps[MAX_N];
int primes[MAX_N];

const int MAXGAP = 73;

void sieve()
{
  is_prime.flip();

  for(int n = 3; n < SQRT_N; n += 2)
    if(is_prime[n>>1])
      for(int j = n * n; j < MAX_N; j += (n<<1))
        is_prime[j>>1] = false;
  is_prime[0] = false;

  prime_gaps[num_primes] = 0;
  primes[num_primes++] = 2;


  //int max_g = 0;

  for(int n = 3; n < MAX_N; n += 2)
    if(is_prime[n/2])
    {
      primes[num_primes] = n;
      prime_gaps[num_primes] = primes[num_primes] - primes[num_primes-1];
      if(prime_gaps[num_primes] == prime_gaps[num_primes-1])
      DEBUG(printf("primes[%d] = %d prime_gaps[%d] = %d\n", num_primes, primes[num_primes], num_primes, prime_gaps[num_primes]));
      ++num_primes;

    }
  //DEBUG(printf("max_g = %d\n", max_g));
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  sieve();
  
  buffered_read input;

  int u, v;

  while(true)
  {
    input.read_unsigned(u);
    input.read_unsigned(v);
    
    DEBUG(printf("U = %d V = %d\n", u, v));

    if(u == 0 && v == 0)
      break;

    if(u > v)
      swap(u, v);

    int *lower = lower_bound(primes, primes + num_primes, u);
    int *upper = upper_bound(primes, primes + num_primes, v);
  
    DEBUG(printf("lower = %d upper = %d\n", *lower, *upper));

    int i = (int) (lower - primes);
    int j = (int) (upper - primes);

    
    DEBUG(printf("i = %d j = %d\n", i, j));

    bool sequence = false;

    for(int k = i; k < j;)
    {

      // Find length of sequence, start and end
      const int start = k;

      DEBUG(printf("k = %d primes[%d] = %d prime_gaps[%d] = %d\n", k, k, primes[k], k+1, prime_gaps[k+1]));

      const int gap = prime_gaps[k+1];

      DEBUG(printf("TARGET gap = %d\n", gap));

      while(gap == prime_gaps[k+1])
      {
        ++k;
        DEBUG(printf("count: gap = %d prime_gaps[%d] = %d\n", gap, k, prime_gaps[k]));
      }

      int length = k - start;

     
      DEBUG(printf("CHECK k = %d start = %d length = %d\n", k, start, length));

      if(length >= 2 && (start + length) < j && ((start > 0) && prime_gaps[start] != gap))
      {
        bool begin = true;
        for(int v = start; v <= start + length; ++v)
        {
          if(!begin)
            printf(" ");
          printf("%d", primes[v]);
          begin = false;
        }
        printf("\n");
      }

      k = start + length;

      //      ++histo[prime_gaps[k]];
    }

    // if(sequence)
    //   printf("\n");

    // Determine most frequently occurring
    // int freq_gap = 0;
    // int freq = 0;

    // for(int k = 0; k < MAXGAP; ++k)
    //   if(histo[k] > freq)
    //   {
    //     freq_gap = k;
    //     freq = histo[k];
    //   }

    // DEBUG(printf("freq_gap = %d freq = %d\n", freq_gap, freq));

    // Now count how many other gaps have the same frequency
    // Should be only 1 if solution good
  //   int count = 0;

  //   for(int k = 0; k < MAXGAP; ++k)
  //     if(histo[k] == freq)
  //       ++count;

  //   DEBUG(printf("count = %d\n", count));

  //   if(count == 1)
  //     printf("The jumping champion is %d\n", freq_gap);
  //   else
  //     printf("No jumping champion\n");
  }

  return 0;
}
