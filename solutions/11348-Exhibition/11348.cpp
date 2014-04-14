#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <unistd.h>


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

const size_t MAX_A = 10001;
const size_t MAX_N = 51;

bitset<MAX_A> stamps[MAX_N];

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  input inp;

  unsigned short k, n, m, a;

  inp.read_short(k);
  DEBUG(printf("k = %u\n", k));

  for(unsigned short t = 1; t <= k; ++t)
  {
    inp.read_short(n);
    DEBUG(printf("n = %u\n", n));
    
    unsigned short counts[MAX_A] = {0};

    for(unsigned short i = 0; i < n; ++i)
    {
      stamps[i].reset();

      inp.read_short(m);
      DEBUG(printf("m = %u\n", m));

      for(unsigned short j = 0; j < m; ++j)
      {
        inp.read_short(a);
        if(!stamps[i].test(a))
          ++counts[a];
        stamps[i].set(a);
        DEBUG(printf("person %u stamp %u counts[%u] = %u\n", i, a, a, counts[a]));
      }
    }

    for(unsigned short i = 0; i < MAX_A; ++i)
    {
      DEBUG(if(counts[i] > 0) printf("counts[%u] = %u\n", i, counts[i]));
      if(counts[i] > 1)
        for(unsigned short j = 0; j < n; ++j)
          stamps[j].set(i, false);
    }

    unsigned total = 0;

    for(unsigned short j = 0; j < n; ++j)
    {
      DEBUG(printf("person %u = %u\n", j, stamps[j].count()));
      total += stamps[j].count();
    }

    DEBUG(printf("total = %u\n", total));

    printf("Case %d:", t);
    for(unsigned short j = 0; j < n; ++j)
      printf(" %.6f%%", (double) stamps[j].count() / (double) total * 100.0);

    printf("\n");
  }

  return 0;
}
