#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
//#define DEBUG_INPUT(X) { X; }
#define DEBUG_INPUT(X)
#else
#define DEBUG(X)
#define DEBUG_INPUT(X)
#endif

using namespace std;

const unsigned MAX_N = 128;

long long matrix[MAX_N * MAX_N];

namespace
{
  const int BLOCK_SIZE_BYTES = MAX_N * MAX_N * 16;

  const int NUM_BLOCKS = 2;

  class input
  {
  public:

    explicit input()
      : size_(0), index_(0), current_(0), eof_(false)
    {
#ifdef ONLINE_JUDGE
      std::ios_base::sync_with_stdio(false);
#endif
      read_block();
    }

    inline bool read_int(long long &v)
    { 
      bool negative = false;
      v = 0;

      if(size_ > 16)
      {
        while(!isdigit(*current_))
        {
          if(*current_ == '-')
            negative = true;
          advance();
        }
        
        while(isdigit(*current_))
        {
          v = v * 10 + *current_ - '0';
          advance();
        }
      }
      else
      {
        while(!isdigit(*current_) && !end_reached())
        {
          if(*current_ == '-')
            negative = true;
          advance();
        }
        
        while(isdigit(*current_) && !end_reached())
        {
          v = v * 10 + *current_ - '0';
          advance();
        }
      }

      if(negative) 
        v *= -1;

      DEBUG_INPUT(printf("size_ = %d v = %d\n", size_, v));

      return !end_reached();
    }

    inline bool end_reached() const
    {
      return // eof_ && 
        size_ == 0;
    }

  private:
    
    inline void advance()
    {
      DEBUG_INPUT(printf("advance (pre) size_ = %d current = [%c]\n", size_, *current_));
      --size_;
      if(size_ == 0)
      {
        //if(!eof_)
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
      //size_ = fread(current_, sizeof(char), BLOCK_SIZE_BYTES);
      size_ = read(0, current_, sizeof(char) * BLOCK_SIZE_BYTES);
      //eof_ = (feof(stdin) != 0);
      eof_ = (size_ == 0);
#ifndef ONLINE_JUDGE
      char output[BLOCK_SIZE_BYTES + 1];
      strncpy(output, blocks_[index_], BLOCK_SIZE_BYTES);
      printf("READ BLOCK [%s]\n", output);
#endif
      DEBUG_INPUT(printf("READ BLOCK size = %d eof = %s\n", size_, eof_ ? "yes" : "no"));
      ++index_;
      index_ = index_ % NUM_BLOCKS;
      DEBUG_INPUT(printf("next index = %d\n", index_));
    }

    // Remaining bytes left in current block
    size_t size_;
    size_t index_;
    char *current_;
    char blocks_[NUM_BLOCKS][BLOCK_SIZE_BYTES];
    bool eof_;
  };

} // namespace

int main()
{
  input inp;
  
  long long t;
  inp.read_int(t);

  for(int q = 1; q <= t; ++q)
  {
    long long n;

    inp.read_int(n);
    DEBUG(printf("N = %d\n", n));

    const long long n2 = n * n;
    DEBUG(printf("N2 = %d\n", n2));
    matrix[0] = 0;

    bool symmetric = true;

    for(int i = 0; i < n2; ++i)
    {
      inp.read_int(matrix[++matrix[0]]);
      if(matrix[matrix[0]] < 0)
        symmetric = false;
    }

    int i = 1;
    int j = n2;
    if(symmetric)
    while(j > i)
    {
      DEBUG(printf("TEST matrix[%d] = %lld matrix[%d] = %lld\n", i, matrix[i], j, matrix[j]));
      if(matrix[i] != matrix[j])
      {
        symmetric = false;
        break;
      }
      ++i;
      --j;
    }
    printf("Test #%d: %symmetric.\n", q, symmetric ? "S" : "Non-s");
  }

  return 0;
}
