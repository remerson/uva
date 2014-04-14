#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#define DEBUG_INPUT(X) //{ X; }
#else
#define DEBUG(X)
#define DEBUG_INPUT(X)
#endif

using namespace std;

namespace
{
  const size_t BLOCK_SIZE_BYTES = 8 * 4096;
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

    inline bool read_short(unsigned short &v)
    { 
      v = 0;

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

        return true;
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

      DEBUG_INPUT(printf("size_ = %d v = %d\n", size_, v));

      return !end_reached();
    }

    inline bool end_reached() const
    {
      return size_ == 0;
    }

  private:
    
    inline void advance()
    {
      DEBUG_INPUT(printf("advance (pre) size_ = %d current = [%c]\n", size_, *current_));
      --size_;
      if(size_ == 0)
      {
        read_block();
      }
      else
      {
        ++current_;
      }
      DEBUG_INPUT(printf("advance (post) size_ = %d current = [%c]\n", size_, *current_));
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
      DEBUG_INPUT(printf("READ BLOCK size = %d\n", size_));
      ++index_;
      index_ = index_ % NUM_BLOCKS;
      DEBUG_INPUT(printf("next index = %d\n", index_));
    }

    // Remaining bytes left in current block
    size_t size_;
    size_t index_;
    char *current_;
    char blocks_[NUM_BLOCKS][BLOCK_SIZE_BYTES];
  };

} // namespace

const unsigned short C_MAX = 64;

int cubes[C_MAX + 1];

// const unsigned short MAX_N = 10240;

// unsigned short x[MAX_N];
// unsigned short y[MAX_N];

int main()
{
  input reader;

  unsigned short i, j, n, x, y;

  int c;

  for(i = 1; i <= C_MAX; ++i)
  {
    cubes[i] = i * i * i;
//     x[i] = 0;
//     y[i] = 0;
  }

//   for(i = 1; i <= C_MAX; ++i)
//     for(j = 1; j <= C_MAX; ++j)
//       c = cub

  while(reader.read_short(n))
  {
    DEBUG(printf("N = %d\n", n));

    if(n == 0)
      break;

    bool solved = false;

    for(y = 1; y <= C_MAX && !solved; ++y)
      for(x = y + 1; x <= C_MAX; ++x)
      {
        DEBUG(printf("cubes[%d] - cubes[%d] = %d n = %d\n", x, y, cubes[x] - cubes[y], n));

        c = cubes[x] - cubes[y];

        if(c == n)
        {
          solved = true;
          break;
        }
        if(c > n) 
          break;
      }
        
    if(!solved)
      printf("No solution\n");
    else
    {
      --y;
      printf("%d %d\n", x, y);
    }
  }
 
  return 0;
}
