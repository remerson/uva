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

using namespace std;

//const size_t B_MAX = 10010;

typedef bitset<10010> Problems;


inline void read_input(input &inp, Problems &p)
{
  unsigned short u, v;

  p.reset();

  inp.read_short(u);

  for(unsigned short i = 0; i < u; ++i)
  {
    inp.read_short(v);
    p.set(v);
  }
}

inline void dump(const Problems &p)
{
  const size_t count = p.count();

  size_t x = 0;

  printf("%u", p.count());

  for(size_t i = 0; x != count; ++i)
    if(p.test(i))
    {
      printf(" %u", i);
      ++x;
    }

  printf("\n");
}

//using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  input inp;

  unsigned short t;

  inp.read_short(t);

  for(unsigned short s = 1; s <= t; ++s)
  {
    Problems a, b, c;

    read_input(inp, a);
    read_input(inp, b);
    read_input(inp, c);

    Problems x = a, y = b, z = c;

    x ^= a & (b | c);
    y ^= b & (a | c);
    z ^= c & (a | b);

    size_t count = x.count();

    if(y.count() > count)
      count = y.count();

    if(z.count() > count)
      count = z.count();


    printf("Case #%hu:\n", s);

    if(x.count() == count)
    {
      printf("1 ");
      dump(x);
    }

    if(y.count() == count)
    {
      printf("2 ");
      dump(y);
    }

    if(z.count() == count)
    {
      printf("3 ");
      dump(z);
    }
    
  }

  return 0;
}
