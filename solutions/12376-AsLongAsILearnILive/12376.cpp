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

    inline bool read_veryshort(unsigned char &v)
    { 
      v = 0;

      // This makes (possibly unsafe) assumptions about how much non-digit space exists
      if(size_ > 4)
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

const unsigned short N_MAX = 112;

unsigned char edges[N_MAX][N_MAX];

unsigned short learn[N_MAX];

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  unsigned short t;

  input inp;

  inp.read_number(t);

  DEBUG(printf("T = %u\n", t));

  for(int s = 1; s <= t; ++s)
  {
    unsigned char n;
    unsigned short m;

    inp.read_veryshort(n);
    inp.read_number(m);

    DEBUG(printf("N = %u M = %u\n", n, m));

    unsigned short l;

    for(char i = 0; i < n; ++i)
    {
      edges[i][0] = 0;
      inp.read_number(l);
      learn[i] = l;
      DEBUG(printf("LEARN %u -> %u\n", i, l));
    }

    unsigned char u, v;

    for(unsigned short i = 0; i < m; ++i)
    {
      inp.read_veryshort(u);
      inp.read_veryshort(v);
      edges[u][++edges[u][0]] = v;
      DEBUG(printf("EDGE %u -> %u\n", u, v));
    }

    u = 0;
    int total = 0;
    unsigned short max_l = 0;
    unsigned char max_v = 0;
    unsigned char i;

    while(edges[u][0] > 0)
    {
      DEBUG(printf("n_edges %u = %u\n", u, edges[u][0]));
      max_l = 0;
      for(i = 1; i <= edges[u][0]; ++i)
      {
        if(learn[edges[u][i]] > max_l)
        {
          max_l = learn[edges[u][i]];
          max_v = edges[u][i];
          DEBUG(printf("Found max_l = %u max_v = %u\n", max_l, max_v));
        }
      }  

      total += max_l;
      u = max_v;

      DEBUG(printf("TOTAL = %u current = %u\n", total, u));
    }

    printf("Case %d: %d %u\n", s, total, u);
      
  }

  return 0;
}
