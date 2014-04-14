#include <cstdio>
#include <cmath>
#include <bitset>
#include <iostream>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#define DEBUG_INPUT(X)
#else
#define DEBUG(X)
#define DEBUG_INPUT(X)
#endif

using namespace std;

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

    template<typename NUM> inline bool read(NUM &v)
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

      DEBUG_INPUT(printf("size_ = %d v = %d\n", size_, v));

      return !end_reached();
    }

//     inline bool read_short(unsigned short &v)
//     { 
//       v = 0;

//       // This makes (possibly unsafe) assumptions about how much non-digit space exists
//       if(size_ > 8)
//       {
//         while(!isdigit(*current_))
//         {
//           --size_;
//           ++current_;
//         }
        
//         while(isdigit(*current_))
//         {
//           v = v * 10 + *current_ - '0';
//           --size_;
//           ++current_;
//         }

//         return true;
//       }
//       else
//       {
//         while(!isdigit(*current_) && !end_reached())
//         {
//           advance();
//         }
        
//         while(isdigit(*current_) && !end_reached())
//         {
//           v = v * 10 + *current_ - '0';
//           advance();
//         }
//       }

//       DEBUG_INPUT(printf("size_ = %d v = %d\n", size_, v));

//       return !end_reached();
//     }

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
      size_ = ::read(0, current_, sizeof(char) * BLOCK_SIZE_BYTES);
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


int main()
{
  input in;

  int n;

  while(in.read(n))
  {
    DEBUG(printf("N = %d\n", n));
    if(n == 0) break;
    bitset<32> v(n);
    const string s = v.to_string();
    const size_t x = s.find_first_of('1');
    printf("The parity of %s is %d (mod 2).\n", s.substr(x).c_str(), v.count());
  }

  return 0;
}
