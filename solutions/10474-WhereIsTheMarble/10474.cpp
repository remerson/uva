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
#include <sstream>

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

const unsigned short M_MAX = 10010;

char value[6];

size_t convert(unsigned short v)
{
  char temp[6] = {0};
  size_t p = 0;
  while(v > 0)
  {
    temp[p++] = v % 10 + 48;
    v /= 10;
  }
  DEBUG(printf("CONVERT p = %hu\n", p));
  for(size_t k = 0; k < p; ++k)
  {
    DEBUG(printf("temp[%u] = %c\n", p - k - 1, temp[p - k - 1]));
    value[k] = temp[p - k - 1];
  }
  DEBUG(value[p] = '\0');
  DEBUG(printf("VALUE = %s\n", value));
  return p;
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  input inp;

  unsigned short n, q, c = 0;

  while(true)
  {
    inp.read_short(n);
    inp.read_short(q);

    DEBUG(printf("N = %hu Q = %hu\n", n, q));

    if(n == 0 && q == 0)
      break;

    unsigned short counts[M_MAX] = {0};

    unsigned short m, m_max = 0;

    for(unsigned short i = 0; i < n; ++i)
    {
      inp.read_short(m);
      ++counts[m];
      DEBUG(printf("counts[%hu] = %hu\n", m, counts[m]));
      if(m > m_max)
      {
        m_max = m;
        DEBUG(printf("m_max = %hu\n", m_max));
      }
    }

    unsigned short positions[M_MAX];

    unsigned short p = 1;

    for(unsigned short i = 1; i <= m_max; ++i)
    {
      if(counts[i] > 0)
      {
        positions[i] = p;
        DEBUG(printf("positions[%hu] = %hu\n", i, p));
        p += counts[i];
      }
    }
    
    size_t len = 0;

    ostringstream buffer;

    buffer << "CASE# " << ++c << ":" << endl;

    //printf("CASE# %hu:\n", ++c);
//     write(1, "CASE# ", 6);
//     len = convert(++c);
//     write(1, value, len);
//     write(1, ":\n", 2);

    for(unsigned short s = 0; s < q; ++s)
    {
      inp.read_short(m);
//       len = convert(m);
//       write(1, value, len);
      if(counts[m] == 0)
        buffer << m << " not found" << endl;
        //        write(1, " not found\n", 11);
        //printf("%hu not found\n", m);
      else
      {
//         write(1, " found at ", 10);
//         len = convert(positions[m]);
//         write(1, value, len);
//         write(1, "\n", 1);      
        buffer << m << " found at " << positions[m] << endl;

        //printf("%hu found at %hu\n", m, positions[m]);
      }
    }

    write(1, buffer.str().c_str(), buffer.str().size());
  }

  return 0;
}
