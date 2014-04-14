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

const unsigned MAX_N = 256;

bool matrix[MAX_N][MAX_N];

unsigned short nodes;

void dump()
{
  printf("DUMP:\n");
  for(int i = 1; i <= nodes; ++i)
  {
    printf("%d:", i);
    for(int j = 1; j <= nodes; ++j)
      if(matrix[i][j])
        printf(" %d", j);
    printf("\n");
  }
}

bitset<MAX_N> visited;
bitset<MAX_N> assigned;
bool bipartite;

unsigned short component[MAX_N];

void dfs(unsigned short i, int m)
{
  DEBUG(printf("DFS %d\n", i));

  // These are stacks
  unsigned short pending[MAX_N * MAX_N];
  unsigned short colours[MAX_N * MAX_N];

  pending[0] = 1;
  pending[1] = i;

  colours[0] = 1;
  colours[0] = true;

  while(pending[0] > 0)
  {
    const unsigned short p = pending[pending[0]--];
    const bool c = colours[colours[0]--];

    if(p > nodes)
      continue;

    if(visited[p])
    {
      if(c != assigned[p])
      {
        DEBUG(printf("MISMATCH %d -> %c but already assigned %c\n", p, (c ? 'R' : 'B'), (assigned[p] ? 'R' : 'B')));
        bipartite = false;
      }
    }
    else
    {
      visited[p] = true;
      assigned[p] = c;
      if(component[p] == 0)
        component[p] = m;
      DEBUG(printf("VISIT %d -> %c\n", p, c ? 'R' : 'B'));

      for(unsigned short j = 1; j <= nodes; ++j)
      {
        if(matrix[p][j])
        {
          pending[++pending[0]] = j;
          colours[++colours[0]] = !c;
        }
      }
    }
  }
}

unsigned short result()
{    
  unsigned short red = 0;
  unsigned short black = 0;

  for(size_t i = 1; i <= nodes; ++i)
  {
    if(visited[i])
    {
      if(assigned[i])
        ++red;
      else
        ++black;
    }
  }

  DEBUG(printf("red = %d black = %d\n", red, black));

  if(bipartite)
  {
    const unsigned short r = max(red, black);

    DEBUG(printf("BIPARTITE r = %d\n", r));
    
    return r;
  }
  else
  {
    DEBUG(printf("NOT B/P r = 0\n"));
    return 0;
  }
}

int main()
{
  input reader;

  unsigned short t, i, j;

  reader.read_short(t);

  DEBUG(printf("T = %d\n", t));

  for(int q = 0; q < t; ++q)
  {
    reader.read_short(nodes);

    DEBUG(printf("N = %d\n", nodes));

    for(i = 1; i <= nodes; ++i)
      for(j = 1; j <= nodes; ++j)
        matrix[i][j] = 0;

    for(i = 1; i <= nodes; ++i)
    {
      unsigned short v;
      reader.read_short(v);
      for(j = 1; j <= v; ++j)
      {
        unsigned short b;
        reader.read_short(b);
        matrix[i][b] = matrix[b][i] = 1;
      }
    }

    DEBUG(dump());

    unsigned short c = 0;

    for(i = 0; i <= nodes; ++i)
      component[i] = 0;

    for(i = 1; i <= nodes; ++i)
    {
      bipartite = true;
      visited.reset();
      dfs(i, i);
      for(j = 1; j <= nodes; ++j)
        DEBUG(printf("component[%d] -> %d\n", j, component[j]));
      if(component[i] == i)
        c += result();
    }

    printf("%d\n", c);
  
  }
 
  return 0;
}
