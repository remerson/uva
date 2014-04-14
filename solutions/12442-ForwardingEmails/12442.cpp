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
#define DEBUG(X) X;
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
      //negative_ = false;
      v = 0;

      if(size_ > 8)
      {
        char *s = current_;

        //        while(!isdigit(*current_))
        while(*current_ > 57 || *current_ < 48)
        {
          //  if(*current_ == '-')
          //  negative_ = true;
          //          --size_;
          ++current_;
        }
        
        while(*current_ > 47 && *current_ < 58)
        {
          v = v * 10 + *current_ - '0';
          //          --size_;
          ++current_;
        }

        size_ -= (current_ - s); // < 16 I hope!

        //if(negative_) 
        //  v *= -1;

        return true;
      }
      else
      {
        while(!isdigit(*current_) && !end_reached())
        {
          //if(*current_ == '-')
          //  negative_ = true;
          advance();
        }
        
        while(isdigit(*current_) && !end_reached())
        {
          v = v * 10 + *current_ - '0';
          advance();
        }
      }

//       if(negative_) 
//         v *= -1;

      //      DEBUG(
      //printf("size_ = %d v = %d\n", size_, v);

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

const int MAX_M = 50010;



int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  //  input inp;
  int t;

  unsigned short forward[MAX_M];

  //  inp.read_number(t);
  if(scanf("%d", &t));
  DEBUG(printf("T = %d\n", t));

  for(int s = 1; s <= t; ++s)
  {
    unsigned short u, v, n;

    //inp.read_number(n);
    if(scanf("%hu", &n));
    
    DEBUG(printf("N = %u\n", n));

    memset(forward, 0, (n + 1) * sizeof(unsigned short));

    for(unsigned short i = 1; i <= n; ++i)
    {
      //inp.read_number(u);
      //inp.read_number(v);
      if(scanf("%hu %hu", &u, &v));
      DEBUG(printf("FORWARD %u -> %u\n", u, v));
      forward[u] = v;
    }

    unsigned short max_l = 0, min_i = 0;

    bitset<MAX_M> visited;    

    DEBUG(int total_cycles = 0);
    DEBUG(int total_nudges = 0);

    DEBUG(printf("START\n"));

    for(unsigned short i = 1; i <= n; ++i)
    {
      if(!visited[i])
      {
        u = forward[i];
        v = forward[u];

        while(u != v)
        {
          u = forward[u];
          v = forward[forward[v]];
          DEBUG(++total_nudges);
        }

        // position from the start of the cycle to i
        unsigned short m = 0;
        u = i;
        while(u != v)
        {
          u = forward[u];
          v = forward[v];
          DEBUG(++total_nudges);
          ++m;
        }

        DEBUG(printf("m = %u u/v = %u\n", m, u));

        // length of the cycle
        unsigned short l = 1 + m;
        v = forward[u];

        while(u != v)
        {
          visited.set(v);
          v = forward[v];
          DEBUG(++total_nudges);
          ++l;
        }

        DEBUG(printf(" %u l = %u max_l = %u visited = %d\n", i, l, max_l, visited.count()));

        DEBUG(++total_cycles);

        if(l > max_l)
        {
          max_l = l;
          min_i = i;
          DEBUG(printf(" min_i = %u max_l = %u visited = %d\n", min_i, max_l, visited.count()));
          
        }
      }
    }

    DEBUG(printf("total_cycles = %d\n", total_cycles));
    DEBUG(printf("total_nudges = %d\n", total_nudges));

    printf("Case %d: %u\n", s, min_i);
  }

  return 0;
}
