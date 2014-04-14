//#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <cstdlib>
//#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const unsigned MAX_V = 1000010;
const unsigned MAX_N = 100010;

const size_t scale = 4;

struct Block
{
  unsigned u; // upper
  unsigned *v;

  Block() : u(0), v(0) { }

  void add(int p)
  {
    if(u == 0) 
    {
      u = scale;
      v = static_cast<unsigned *>(realloc(v, u * sizeof(unsigned)));
      v[0] = 0;
    }
    else if(v[0] == (u - 1))
    {
      u *= scale;
      if(u > MAX_N) u = MAX_N;
      v = static_cast<unsigned *>(realloc(v, u * sizeof(unsigned)));
    }
    v[++v[0]] = p;
  }

};

inline char *read_value(unsigned &u, char *b)
{
  while(!isdigit(*b)) ++b;
  u = 0;
  while(isdigit(*b)) 
  {
    u = u * 10 + *b - '0';
    ++b;
  }
  return b;
}

int len;

inline char *write_value(int i, char *b)
{
  char const digit[] = "0123456789";
  char* p = b;
  if(i<0){
    *p++ = '-';
    i = -1;
  }
  int shifter = i;
  do{ //Move to where representation ends
    ++p;
    shifter = shifter/10;
  }while(shifter);
  char *e = p;
  ++e;
  *p = '\n';
  do{ //Move back, inserting digits as u go
    *--p = digit[i%10];
    i = i/10;
  }while(i);
  len += e - b;
  DEBUG(printf("LEN = %d\n", len));
  return e;
}

const int B_MAX = 1024 * 1024;

int main()
{
  int n, m;

  Block values[MAX_N];
  char buffer[B_MAX];

  while(scanf("%d %d\n", &n, &m) == 2)
  {
    unsigned hash[MAX_V] = {0};
    
    // Reset
    for(int i = 1; i <= n; ++i) if(values[i].u > 0) values[i].v[0] = 0;

    char * b= fgets(buffer, B_MAX, stdin);

    DEBUG(printf("BUFFER [%s]", buffer));

    unsigned v;
    unsigned p = 0;

    for(int i = 1; i <= n; ++i)
    {
      b = read_value(v, b);
      
      if(hash[v] == 0) hash[v] = ++p;

      values[hash[v]].add(i);
    }

    unsigned k;

    char second[32];
    
    char *o = buffer;

    len = 0;

    for(int i = 0; i < m; ++i)
    {
      char *b = fgets(second, 31, stdin);

      b = read_value(k, b);
      b = read_value(v, b);

      if(hash[v] == 0 || k > values[hash[v]].v[0])
      {
        DEBUG(printf("WRITE VALUE 0\n"));
        o = write_value(0, o);
        DEBUG(printf("o = [%s]\n", buffer));
      }
      else
      {
        DEBUG(printf("WRITE VALUE %u\n", values[hash[v]].v[k]));
        o = write_value(static_cast<int>(values[hash[v]].v[k]), o);
        DEBUG(printf("o = [%s]\n", buffer));
      }
    }
    
    *o = '\0';
    ++o;

    //printf("%s", buffer);
    write(1, buffer, len);
  }
  return 0;
}
