#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <bitset>
#include <map>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

namespace io
{
  inline char *read_unsigned(unsigned &v, char *b)
  {
    while(!isdigit(*b)) ++b;
    v = 0;

    while(isdigit(*b) || *b == '.') 
      if(*b != '.') v = v * 10 + *(b++) - '0';
      else ++b;
    return b;
  }

  inline char *read_string(string &v, char *b)
  {
    while(!isalpha(*b) && !isdigit(*b)) ++b;

    char *s = b;

    while(isalpha(*b) || isdigit(*b)) ++b;

    *b = '\0';
    v = string(s);

    while(isspace(*b)) ++b;

    return b;
  }
}

const unsigned P_MAX = 64;

const unsigned N_MAX = 32;

const unsigned B_MAX = P_MAX * N_MAX * 2;

using namespace io;

int main()
{
  char buffer[B_MAX];

  unsigned p, g;

  typedef map<string, unsigned> PartyMap;

  while(scanf("%u %u\n", &p, &g) == 2)
  {
    DEBUG(printf("P = %u G = %u\n", p, g));

    PartyMap allVotes;

    for(unsigned i = 0; i < p; ++i)
    {
      char *b = fgets(buffer, B_MAX - 1, stdin);

      DEBUG(printf("BUFFER [%s]\n", buffer));

      string name;
      unsigned vote;

      b = read_string(name, b);
      b = read_unsigned(vote, b);

      DEBUG(printf("NAME = [%s] VOTE = %u\n", name.c_str(), vote));

      allVotes.insert(PartyMap::value_type(name, vote));
    }

    for(unsigned i = 1; i <= g; ++i)
    {
      unsigned total = 0;

      char *b = fgets(buffer, B_MAX - 1, stdin);

      DEBUG(printf("BUFFER [%s]\n", buffer));

      do
      {
        string name;
        b = read_string(name, b);
        total += allVotes.find(name)->second;
        DEBUG(printf("READ [%s] total = %u\n", name.c_str(), total));
        ++b;
      } while(*b == '+');

      char *c = b;
      ++c;

      unsigned check;
      char *d = read_unsigned(check, b);
      check *= 10;
      DEBUG(printf("CHECKVAL = %u\n", check));

      bool correct = false;

      if(*b == '>' && *c == ' ')
      {
        DEBUG(printf("CHECK %u > %u\n", total, check));
        if(total > check) correct = true;
      }
        
      if(*b == '<' && *c == ' ')
      {
        DEBUG(printf("CHECK %u < %u\n", total, check));
        if(total < check) correct = true;
      }

      if(*b == '=' && *c == ' ')
      {
        DEBUG(printf("CHECK %u = %u\n", total, check));
        if(total == check) correct = true;
      }

      if(*b == '>' && *c == '=')
      {
        DEBUG(printf("CHECK %u >= %u\n", total, check));
        if(total >= check) correct = true;
      }

      if(*b == '<' && *c == '=')
      {
        DEBUG(printf("CHECK %u <= %u\n", total, check));
        if(total <= check) correct = true;
      }

      printf("Guess #%u was %scorrect.\n", i, (!correct ? "in" : ""));
    }
  }

  return 0;
}
