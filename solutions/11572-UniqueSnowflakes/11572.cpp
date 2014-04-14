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
  const size_t BLOCK_SIZE_BYTES = 2 * 4096;
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
      v = 0;

      if(size_ > 16)
      {
        char *s = current_;
        char *c = current_;

        while(*c > 57 || *c < 48)
          ++c;
        
        while(*c > 47 && *c < 58)
        {
          v = v * 10 + *c - '0';
          ++c;
        }

        size_ -= (c - s); // < 16 I hope!
        current_ = c;

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

// Max number snowflakes in input
const size_t MAX_S = 1000010;
//int visited[MAX_S];

const size_t MAX_H = 1 * MAX_S;
int visited[MAX_H];
int hash_slots[MAX_H];

inline int hash(int a)
{
    // a = (a+0x7ed55d16) + (a<<12);
//     //a = (a^0xc761c23c) ^ (a>>19);
//     //a = (a+0x165667b1) + (a<<5);
//     a = (a+0xd3a2646c) ^ (a<<9);
//     a = (a+0xfd7046c5) + (a<<3);
//     a = (a^0xb55a4f09) ^ (a>>16);
    a = (a+0x7ed55d16) + (a<<12);
    //a = (a^0xc761c23c) ^ (a>>19);
    //a = (a+0x165667b1) + (a<<5);
    a = (a+0xd3a2646c) ^ (a>>9);
    //    a = (a+0xfd7046c5) + (a<<3);
    //    a = (a^0xb55a4f09) ^ (a>>16);

    return a;
    //  return 1;
}

inline int hash(int a, int n)
{
  //bool assigned = false;

  //DEBUG(printf("  hash(%d, %d)\n", a, n));

  int h = abs(hash(a) % static_cast<int>(MAX_H));

  do
  {
    DEBUG(printf(" HASH %d -> %d\n", a, h));

    if(hash_slots[h] == a)
    {
      break;
    }

    // empty slot, assign
    if(hash_slots[h] == -1)
    {
      hash_slots[h] = a;
      break;
    }

//     if(hash_slots[h] == a)
//     {
//       break;
//     }

    DEBUG(printf(" COLLISION\n"));
    
    // collision, try again, open linear
    h = (h + 1) % MAX_H;
  } 
  while(true);
    
  return h;
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  input inp;

  unsigned t;

  inp.read_number(t);

  DEBUG(printf("T = %d\n", t));

  for(unsigned s = 0; s < t; ++s)
  {
    unsigned n;
    inp.read_number(n);

    DEBUG(printf("===== S = %d, N = %d\n", s, n));

    memset(&hash_slots[0], -1, MAX_H * sizeof(int));
    memset(&visited[0], -1, MAX_H * sizeof(int));

    DEBUG(for(int i = 0; i < n; ++i) printf("hash_slots[%d] = %d\n", i, hash_slots[i]););

    int v, h;

    int previous = 0;
    int length = 1;
    int longest = 1;

    inp.read_number(v);
    h = hash(v, n);
    visited[h] = 0;

    DEBUG(printf("START longest = %d length = %d\n", longest, length));

    for(int i = 1; i < n; ++i)
    {
      inp.read_number(v);
      h = hash(v, n);

      previous = visited[h];
      visited[h] = i;

      DEBUG(printf("i = %d previous = %d\n", i, previous));

      if(previous == -1 || (i - length) > previous)
      {
        ++length;
        DEBUG(printf("length = %d\n", length));
      }
      else
      {
        if(length > longest)
          longest = length;
        length = i - previous;
        DEBUG(printf("longest = %d length = %d\n", longest, length));
      }
    }
      
    if(length > longest)
      longest = length;
    
    printf("%d\n", longest);
  }

  return 0;
}
