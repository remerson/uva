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
#define DEBUG(X) X;
#else
#define DEBUG(X)
#endif

using namespace std;

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

// The largest prime number to generate up to (this value itself does not have to be prime)
const size_t MAX_PRIME = 10000;

// A count of the number of prime numbers that will be generated (used for sizing the array)
const size_t NUM_PRIME = MAX_PRIME / 3;

bitset<MAX_PRIME> is_prime;
int primes[NUM_PRIME];
size_t max_index = 0;

// int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 
// , 31, 37, 41, 43, 47, 53, 59, 61, 67, 71 
// , 73, 79, 83, 89, 97, 101, 103, 107, 109, 113 
// , 127, 131, 137, 139, 149, 151, 157, 163, 167, 173 
// , 179, 181, 191, 193, 197, 199, 211, 223, 227, 229 
// , 233, 239, 241, 251, 257, 263, 269, 271, 277, 281 
// , 283, 293, 307, 311, 313, 317, 331, 337, 347, 349 
// , 353, 359, 367, 373, 379, 383, 389, 397, 401, 409 
// , 419, 421, 431, 433, 439, 443, 449, 457, 461, 463 
// , 467, 479, 487, 491, 499, 503, 509, 521, 523, 541 
// , 547, 557, 563, 569, 571, 577, 587, 593, 599, 601 
// , 607, 613, 617, 619, 631, 641, 643, 647, 653, 659 
// , 661, 673, 677, 683, 691, 701, 709, 719, 727, 733 
// , 739, 743, 751, 757, 761, 769, 773, 787, 797, 809 
// , 811, 821, 823, 827, 829, 839, 853, 857, 859, 863 
// , 877, 881, 883, 887, 907, 911, 919, 929, 937, 941 
// , 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013 
// , 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069 
// , 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151 
// , 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223 
// , 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291 
// , 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373 
// , 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451 
// , 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511 
// , 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583 
// , 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657 
// , 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733 
// , 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811 
// , 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889 
// , 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987 
// , 1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053 
// , 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129 
// , 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213 
// , 2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287 
// , 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357 
// , 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423 
// , 2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531 
// , 2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617 
// , 2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687 
// , 2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741 
// , 2749, 2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819 
// , 2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903 
// , 2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999 
// , 3001, 3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079 
// , 3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181 
//   , 3187, 3191, 3203, 3209, 3217, 3221, 3229 };

void sieve()
{
  for(size_t i = 0; i < MAX_PRIME; ++i) 
    is_prime[i] = true;

  is_prime[0] = false;
  is_prime[1] = false;
  
  max_index = 0;

  // 2 as a special case
  for(size_t j = 2; j < MAX_PRIME; j += 2)
    is_prime[j] = false;

  primes[max_index++] = 2;

  // Odd primes only
  for(size_t i = 3; i < MAX_PRIME; i+=2)
  {
    if(is_prime[i])
    {
      for(size_t j = i; j < MAX_PRIME; j += i) 
        is_prime[j] = false;

      primes[max_index++] = i;
      DEBUG(if(max_index >= NUM_PRIME) { printf("ERROR max_index = %ld exceeded at prime = %d\n", max_index, primes[max_index - 1]); abort(); });
    }
  }
}

int factor(int a, int c)
{
  DEBUG(printf("FACTOR %d %d\n", a, c));
  int count_a, count_c;
  int b = 1;
  
  // 2 as special case
  count_a = 0;
  count_c = 0;
    
  while((a & 1) == 0)
  {
    ++count_a;
    a = a >> 1;
  }
      
  while((c & 1) == 0)
  {
    ++count_c;
    c = c >> 1;
  }

  //DEBUG(printf("For prime = %d count_a = %d count_c = %d\n", primes[p], count_a, count_c));

  if(count_c > count_a)
  {
    b = b << count_c;
  }

  // general case
  for(size_t p = 1; (a > 1 && c > 1 && a != c); ++p)
  {
    DEBUG(printf("FACTOR a = %d b = %d c = %d p = %d\n", a, b, c, primes[p]));

    count_a = 0;
    count_c = 0;
    
    while(a % primes[p] == 0)
    {
      ++count_a;
      a /= primes[p];
    }
      
    while(c % primes[p] == 0)
    {
      ++count_c;
      c /= primes[p];
    }

    DEBUG(printf("For prime = %d count_a = %d count_c = %d\n", primes[p], count_a, count_c));

    if(count_c > count_a)
    {
      for(int k = 0; k < count_c; ++k)
        b = b * primes[p];
    }

    DEBUG(if(count_c > 1) printf("STATS p = %d count_c = %d\n", primes[p], count_c));

  }

  if(a == 1 && c > 1)
    b *= c;
  
  DEBUG(printf("Done. a = %d b = %d c = %d\n", a, b, c));

  return b;
}

const int B_MAX = 12 * 100010;

char value[11];

inline size_t convert(int v)
{
  char temp[11] = {0};
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

  int t;

  inp.read_number(t);

  DEBUG(printf("T = %d\n", t));

  int a, b, c;

  sieve();

  char buffer[B_MAX + 1];
  int f = 0;

  for(int s = 0; s < t; ++s)
  {
    inp.read_number(a);
    inp.read_number(c);
    DEBUG(printf("===== a = %d c = %d\n", a, c));

    const int v = c / a;
    
    if(v * a == c)
    {
      if(a != c)
        b = factor(a, c);
      else
        b = 1;
      const int l = convert(b);
      memcpy(&buffer[f], &value[0], l);
      f += l;
      buffer[f++] = '\n';
      //printf("%d\n", b);
    }
    else
    {
      //printf("NO SOLUTION\n");
            memcpy(&buffer[f], "NO SOLUTION\n", 12);
      f += 12;
    }
  }

  write(1, buffer, f);
 
  return 0;
}
