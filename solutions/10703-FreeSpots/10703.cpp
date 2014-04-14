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

const unsigned MAX_W = 512;
const unsigned MAX_H = 512;

bitset<MAX_W * MAX_H> board;

int main()
{
  unsigned short w, h, n;
  unsigned short x1, x2, y1, y2;
  int i, j, k;

  input reader;

  while(reader.read_short(w) && reader.read_short(h) && reader.read_short(n))
  {
    DEBUG(printf("W = %d H = %d N = %d\n", w, h, n));

    if(w == 0 && h == 0 && n == 0) break;

    board.reset();

    for(k = 0; k < n; ++k)
    {
      reader.read_short(x1);
      reader.read_short(y1);
      reader.read_short(x2);
      reader.read_short(y2);

      DEBUG(printf("READ x1 = %d y1 = %d x2 = %d y2 = %d\n", x1, y1, x2, y2));

      const int min_x = min(x1, x2);
      const int max_x = max(x1, x2);

      const int min_y = min(y1, y2);
      const int max_y = max(y1, y2);

      // x = col = w
      // y = row = h
      for(i = min_x; i <= max_x; ++i)
        for(j = min_y; j <= max_y; ++j)
          board.set(i * h + j);

    }

    DEBUG(printf("s = %d dim = %d\n", board.count(), w * h));

    const size_t s = (w * h) - board.count();
    
    if(s == 0)
      write(1, "There is no empty spots.\n", 25);
    else if(s == 1)
      write(1, "There is one empty spot.\n", 25);
    else
      printf("There are %d empty spots.\n", s);
  }

  return 0;
}
