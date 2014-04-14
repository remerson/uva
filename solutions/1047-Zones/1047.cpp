#include <cstdio>

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
// Cut and paste everything from below here
//

// #ifndef ONLINE_JUDGE
// #define DEBUG_READ(X) { X; }
// #else
#define DEBUG_READ(X)
//#endif

namespace
{
  const size_t BLOCK_SIZE_BYTES = 4096;
  const size_t NUM_BLOCKS = 2;

  //
  // Optimised integer (signed/unsigned) only read from stdin.
  //
  // This can only read integers.
  //
  // Assumes the input file only contains number characters (0-9)
  // or non-readable characters (< ASCII 47).
  //
  // Input containing ASCII values above 57 ('9') will give
  // unpredictable (bad) results. You have been warned.
  //
  // Do not mix using this with scanf/cin. It will not work.
  //
  // Copying is also probably a bad idea.
  //
  // It is intended to be instantiated once only up front in main()
  // and then used until termination.
  //

  class buffered_read
  {
  public:

    buffered_read()
      : current_(0), index_(0), size_(0)
    {
#ifdef ONLINE_JUDGE
      //std::ios_base::sync_with_stdio(false);
#endif
      read_block();
    }
    
    //
    // Read a signed value into v.
    //
    // Returns a flag to indicate whether more input is available (true)
    // or not (false).
    //
    // The type NUM must support operators: =, * and +.
    // 
    // It must also support signed values and be large enough to hold
    // the value read.
    //
    template<typename NUM> bool read_signed(NUM &v)
    { 
      bool negative = false;
      v = 0;

      // "fast" path - "far" from end of block
      if(size_ > 16)
      {
        char *current = current_;
        const char *start = current_;

        while(*current < 48)
        {
          if(*current == '-')
            negative = true;

          ++current;
        }

        do
        {
          v = v * 10 + *current - '0';
          ++current;
        } while(*current > 47);

        if(negative)
          v *= -1;

        size_ -= (current - start);
        current_ = current;

        DEBUG_READ(printf(" -- (fast) read_signed = %d\n", v));
        return true; // must be more to read (although more carefully)
      }

      // "slow" path - near end of block
      while(*current_ < 48 && !end_reached())
      {
        if(*current_ == '-')
          negative = true;
        advance();
      }
        
      while(*current_ > 47 && !end_reached())
      {
        v = v * 10 + *current_ - '0';
        advance();
      }

      if(negative)
        v *= -1;
      
      DEBUG_READ(printf(" -- (slow) read_signed = %d\n", v));
      return !end_reached();
    }

    //
    // Read an signed value into v. Optimised to not bother looking
    // for a leading unary minus.
    //
    // Returns a flag to indicate whether more input is available (true)
    // or not (false).
    //
    // The type NUM must support operators: =, * and +.
    // 
    // It must also support unsigned values and be large enough to hold
    // the value read.
    //
    template<typename NUM> bool read_unsigned(NUM &v)
    { 
      v = 0;

      // "fast" path
      if(size_ > 16)
      {
        char *current = current_;
        const char *start = current_;

        while(*current < 48)
          ++current;
        
        do
        {
          v = v * 10 + *current - '0';
          ++current;
        } while(*current > 47);

        size_ -= (current - start);
        current_ = current;

        DEBUG_READ(printf(" -- (fast) read_unsigned = %u\n", v));
        return true; // must be more to read (although more carefully)
      }

      // "slow" path
      while(*current_ < 48 && !end_reached())
        advance();

      while(*current_ > 47 && !end_reached())
      {
        v = v * 10 + *current_ - '0';
        advance();
      }
      
      DEBUG_READ(printf(" -- (slow) read_unsigned = %u\n", v));
      return !end_reached();
    }

    bool end_reached() const
    {
      return size_ == 0;
    }

  private:
    
    void advance()
    {
      --size_;
      if(size_ == 0)
      {
        read_block();
      }
      else
      {
        ++current_;
      }
    }

    void read_block()
    {
      current_ = &blocks_[index_][0];
      size_ = read(0, current_, sizeof(char) * BLOCK_SIZE_BYTES);
      ++index_;
      index_ = (index_ % NUM_BLOCKS);
    }

    // Remaining bytes left in current block
    char *current_;
    char blocks_[NUM_BLOCKS][BLOCK_SIZE_BYTES];
    size_t index_;
    size_t size_;
  };

} // namespace

//
// End of buffered_read
//
///////////////////////////////////////////////////////////////////////////////

const size_t MAX_N = 20;

unsigned tower_coverage[MAX_N];

const size_t MAX_T = 10;

unsigned overlap_tower[MAX_T];
unsigned overlap_coverage[MAX_T]; 

void dump_mask(unsigned x, unsigned n)
{
  for(unsigned i = 0; i < n; ++i)
    if(x & (1 << i))
      printf(" %u", i+1);
  printf("\n");
}

unsigned hamming(unsigned x)
{
  unsigned c = 0;
  for(; x; ++c)
    x &= x-1;
  return c;
}

// Uses Gosper's Hack to determine the next combination
// C(n, k) - see main for-loop for bounds/usage.
unsigned gosper(unsigned x)
{
  const unsigned u = x & (-x);
  const unsigned v = u + x;
  return v + (((v ^ x) / u) >> 2);
}

// 10-bit Hamming lookup table
unsigned char bits[1024];

const unsigned mask = (1 << 10) - 1;

// Custom 20-bit (2-split) Hamming using lookup
unsigned bitcount(unsigned x)
{
  return bits[x & mask] + bits[x >> 10];
}

const int debruijn[32] = 
{
  0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8, 
  31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
};

int main()
{
  buffered_read input;

  unsigned n, r, case_number = 0;

  for(unsigned short i = 0; i < 1024; ++i)
    bits[i] = hamming(i);

  while(!input.end_reached())
  {
    input.read_unsigned(n);
    input.read_unsigned(r);
    
    if(n == 0 && r == 0)
      break;

    DEBUG(printf("N = %d R = %d\n", n, r));

    for(unsigned i = 0; i < n; ++i)
    {
      input.read_unsigned(tower_coverage[i]);
      DEBUG(printf("Tower %u coverage = %u\n", i+1, tower_coverage[i]));
    }

    unsigned m;

    input.read_unsigned(m);

    DEBUG(printf("M = %u\n", m));

    for(unsigned i = 0; i < m; ++i)
    {
      unsigned t;
      input.read_unsigned(t);

      unsigned u = 0;

      for(unsigned j = 0; j < t; ++j)
      {
        unsigned v;
        input.read_unsigned(v);
        u |= 1 << (v-1);
      }

      unsigned c;
      input.read_unsigned(c);

      overlap_tower[i] = u;
      overlap_coverage[i] = c;

      DEBUG(printf("Overlap coverage = %u towers:", c); dump_mask(u, n););
    }

    unsigned max_customers = 0;
    unsigned recommended_combo = 0, previous_combo;

    unsigned tower_customers = 0;
    for(size_t i = 0; i < r; ++i)
      tower_customers += tower_coverage[i];
    
    bool first = true;

    for(unsigned combo = ((1 << r) - 1); (combo >> n) == 0; combo = gosper(combo))
    {
      DEBUG(printf("==== Combo:"); dump_mask(combo, n););

      if(!first)
      {
        const unsigned both = combo ^ previous_combo;

        unsigned sub_towers = previous_combo & both;
        while(sub_towers)
        {
          const unsigned b = sub_towers - 1;
          const unsigned a = sub_towers & ~b;
          tower_customers -= tower_coverage[debruijn[(((a & -a) * 0x077CB531U)) >> 27]];
          DEBUG(printf("Subtract: %u\n", tower_coverage[debruijn[(((a & -a) * 0x077CB531U)) >> 27]])); 
          sub_towers &= b;
        }

        unsigned add_towers = combo & both;
        while(add_towers)
        {
          const unsigned b = add_towers - 1;
          const unsigned a = add_towers & ~b;
          tower_customers += tower_coverage[debruijn[(((a & -a) * 0x077CB531U)) >> 27]];
          DEBUG(printf("Add: %u\n", tower_coverage[debruijn[(((a & -a) * 0x077CB531U)) >> 27]]));
          add_towers &= b;
        }        
      }

      first = false;

      DEBUG(printf("Tower customers = %u\n", tower_customers));

      unsigned combo_customers = tower_customers;

      for(size_t i = 0; i < m; ++i)
      {
        const int overlap = bitcount(overlap_tower[i] & combo) - 1;
        if(overlap > 0)
        {
          DEBUG(printf("Overlap = %u coverage = %u:", overlap, overlap_coverage[i]); dump_mask(overlap_tower[i], n););
          combo_customers -= overlap * overlap_coverage[i];
        }
      }

      DEBUG(printf("Combo customers = %u\n", combo_customers));

      if(combo_customers > max_customers)
      {
        max_customers = combo_customers;
        recommended_combo = combo;
      }

      previous_combo = combo;
    }

    printf("Case Number  %u\nNumber of Customers: %u\nLocations recommended:", ++case_number, max_customers);
    dump_mask(recommended_combo, n);
    printf("\n");
  }

  return 0;
}
