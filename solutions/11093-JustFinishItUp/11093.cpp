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

// Page buffered (integer) read
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
      strncpy(output, blocks_[index_], std::min(size_, BLOCK_SIZE_BYTES));
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



using namespace std;



const int N_MAX = 100010;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  input inp;

  int t;

  inp.read_number(t);

  for(int s = 1; s <= t; ++s)
  {
    int n;
    inp.read_number(n);

    DEBUG(printf("N = %d\n", n));

    int a[N_MAX];
    int b[N_MAX];

    int sum_a = 0, sum_b = 0;

    for(int i = 0; i < n; ++i)
    {
      inp.read_number(a[i]);
      sum_a += a[i];
    }

    for(int i = 0; i < n; ++i)
    {
      inp.read_number(b[i]);
      sum_b += b[i];
    }

    DEBUG(printf("sum_a = %d sum_b = %d\n", sum_a, sum_b));

    if(sum_b > sum_a)
    {
      printf("Case %d: Not possible\n", s);
    }
    else
    {
      for(int i = 0; i < n; ++i)
      {
        int avail = 0;

        bool solution = true;

        for(int j = 0; j < n; ++j)
        {
          avail += a[(i + j) % n];
          avail -= b[(i + j) % n];
          if(avail < 0)
          {
            solution = false;
            break;
          }
        }

        if(solution)
        {
          printf("Case %d: Possible from station %d\n", s, i + 1);
          break;
        }
      }
    }
  }

  return 0;
}
