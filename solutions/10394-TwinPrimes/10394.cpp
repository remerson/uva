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


namespace
{
  //
  // NUM_PRIMES should be sqrt(MAX_PRIME)
  //
  // No space compression - memory footprint is MAX_PRIME / 8 bytes + NUM_PRIMES
  //
  template<unsigned MAX_PRIME, unsigned NUM_PRIMES> class prime_sieve
  {
  public:

    explicit prime_sieve()
      : num_(0)
    {
      for(size_t i = 0; i < MAX_PRIME; ++i) 
        prime_[i] = true;

      prime_[0] = false;
      prime_[1] = false;
      prime_[2] = true;

      // Even prime only
      for(size_t i = 4; i < MAX_PRIME; i+=2)
        prime_[i] = false;

      const size_t max_s = static_cast<size_t>(sqrt(MAX_PRIME));

      // Odd primes only
      for(size_t i = 3; i < max_s; i+=2)
        if(prime_[i])
          for(size_t j = (i * i); j < MAX_PRIME; j += i)
            prime_[j] = false;

    }

    // k < MAX_PRIME
    inline bool is_prime(unsigned k) const
    {
      return prime_.test(k);
    }

    // Create an internal list of all primes (for use by get_prime()
    // below). Optional, in case you don't need it and only want the
    // basic sieve.
    void generate()
    {
      // Bin values
      values_[num_++] = 2;

      for(size_t i = 3; i < MAX_PRIME; i+=2)
      {
        if(prime_.test(i))
        {
          values_[num_++] = i;
          DEBUG(printf("prime[%u] = %d\n", num_ - 1, values_[num_ - 1]));
        }
      }

      DEBUG(printf("Found %u primes.\n", num_));
    }

    // Returns the k'th prime. Caller is responsible for bounds check.
    // k < NUM_PRIMES. Must call generate() first.
    inline unsigned get_prime(unsigned k) const
    {
      return values_[k];
    }

    // Returns the number of prime values cached
    inline size_t num_primes() const
    {
      return num_;
    }

  private:

    bitset<MAX_PRIME> prime_;
    unsigned values_[NUM_PRIMES];
    size_t num_;
  };
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  const unsigned MAX_PRIME = 18410000;
  const unsigned MAX_PAIR = 100010;
  
  prime_sieve<MAX_PRIME, 1> sieve;

  unsigned a[MAX_PAIR];
  unsigned b[MAX_PAIR];

  size_t num = 1;

  a[num] = 3;
  b[num] = 5;
  ++num;

  for(size_t k = 5; k < MAX_PRIME; k += 6)
  {
    if(sieve.is_prime(k) && sieve.is_prime(k + 2))
    {
      a[num] = k;
      b[num] = k + 2;
      DEBUG(printf("%u %u PAIR %u %u\n", k, num, a[num], b[num]));
      ++num;
    }
  }

  input inp;

  int v;

  while(inp.read_number(v))
    printf("(%u, %u)\n", a[v], b[v]);

  return 0;
}
