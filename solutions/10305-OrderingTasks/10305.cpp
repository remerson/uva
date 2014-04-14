#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
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

//const unsigned MAX_N = 512;

namespace
{
  // This is sized for a total buffer size of 1Mb
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

//     template<typename NUM> inline bool read(NUM &v)
//     { 
//       negative_ = false;
//       v = 0;

//       if(size_ > 16)
//       {
//         while(!isdigit(*current_))
//         {
//           if(*current_ == '-')
//             negative_ = true;
//           --size_;
//           ++current_;
//         }
        
//         while(isdigit(*current_))
//         {
//           v = v * 10 + *current_ - '0';
//           --size_;
//           ++current_;
//         }

//         if(negative_) 
//           v *= -1;

//         return true;
//       }
//       else
//       {
//         while(!isdigit(*current_) && !end_reached())
//         {
//           if(*current_ == '-')
//             negative_ = true;
//           advance();
//         }
        
//         while(isdigit(*current_) && !end_reached())
//         {
//           v = v * 10 + *current_ - '0';
//           advance();
//         }
//       }

//       if(negative_) 
//         v *= -1;

//       DEBUG_INPUT(printf("size_ = %d v = %d\n", size_, v));

//       return !end_reached();
//     }

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
    bool negative_;
  };

} // namespace

const unsigned MAX_N = 2 << 7;

char edges[MAX_N][MAX_N];

typedef bitset<MAX_N> mark;

mark visited;
mark added;

char order[MAX_N];

void visit(char n)
{
  if(visited[n])
  {
    DEBUG(printf("Not DAG\n"));
    return;
  }

  if(!added[n])
  {
    visited[n] = true;
    for(int k = 1; k <= edges[n][0]; ++k)
      visit(edges[n][k]);
    order[++order[0]] = n;
    added[n] = true;
  }
}

int main()
{
  input inp;
  unsigned short n, m;
  unsigned short i, j, k;
  unsigned short a, b;
  
  while(inp.read_short(n) && inp.read_short(m))
  {
    DEBUG(printf("N = %d M = %d\n", n, m));

    if(n == 0 && m == 0)
      break;

    for(i = 0; i <= n; ++i)
      edges[i][0] = 0;
      
    for(i = 0; i < m; ++i)
    {
      inp.read_short(a);
      inp.read_short(b);
      edges[b][++edges[b][0]] = a;
      DEBUG(printf("edges[%d][%d] = %d\n", b, edges[b][0], a));
    }

    order[0] = 0;
    visited.reset();
    added.reset();

    while(visited.count() < n && added.count() < n)
    {
      for(i = 1; i <= n; ++i)
        if(!visited[i]) visit(i);
    }

    printf("%d", order[1]);
    for(i = 2; i <= n; ++i)
      printf(" %d", order[i]);
    printf("\n");
  }

  return 0;
}
