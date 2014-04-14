#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#include <cstring>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;
typedef enum
  {
    NONE,

    OPEN_ROUND,
    OPEN_SQUARE,
    OPEN_CURLY,
    OPEN_ANGLED,
    OPEN_FUNNY,

    CLOSE_ROUND,
    CLOSE_SQUARE,
    CLOSE_CURLY,
    CLOSE_ANGLED,
    CLOSE_FUNNY
  } bracket;

const char *to_string(bracket b)
{
  switch(b)
  {
  case NONE:
    return "NONE";
  case OPEN_ROUND:
    return "OPEN_ROUND";
  case OPEN_SQUARE:
    return "OPEN_SQUARE";
  case OPEN_CURLY:
    return "OPEN_CURLY";
  case OPEN_ANGLED:
    return "OPEN_ANGLED";
  case OPEN_FUNNY:
    return "OPEN_FUNNY";
  case CLOSE_ROUND:
    return "CLOSE_ROUND";
  case CLOSE_SQUARE:
    return "CLOSE_SQUARE";
  case CLOSE_CURLY:
    return "CLOSE_CURLY";
  case CLOSE_FUNNY:
    return "CLOSE_FUNNY";
  default:
    return "unknown";
  };
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  const int B_MAX = 4096;

  char buffer[B_MAX + 1] = {0};

  while(fgets(buffer, B_MAX, stdin))
  {
    DEBUG(printf("BUFFER [%s]\n", buffer));

    const size_t l = strlen(buffer);

    stack<bracket> balance;

    bool ok = true;

    size_t i = 0;
    size_t v = 0;

    for(i = 0; i < l; ++i)
    {
      char c = buffer[i];

      DEBUG(printf("buffer[%d] = %c\n", i, c));

      bracket b = NONE;

      switch(c)
      {
      case '(':
        if(buffer[i+1] == '*')
        {
          b = OPEN_FUNNY;
          ++i;
        }
        else
          b = OPEN_ROUND;
        break;
      case '*':
        if(buffer[i+1] == ')')
        {
          b = CLOSE_FUNNY;
          ++i;
        }
        break;
      case ')':
        b = CLOSE_ROUND;
        break;
      case '[':
        b = OPEN_SQUARE;
        break;
      case ']':
        b = CLOSE_SQUARE;
        break;
      case '<':
        b = OPEN_ANGLED;
        break;
      case '>':
        b = CLOSE_ANGLED;
        break;
      case '{':
        b = OPEN_CURLY;
        break;
      case '}':
        b = CLOSE_CURLY;
        break;
        
      }

      // Have read one "logical" char
      ++v;
      
      DEBUG(printf("b = %s\n", to_string(b)));

      switch(b)
      {
      case OPEN_ROUND:
      case OPEN_SQUARE:
      case OPEN_ANGLED:
      case OPEN_CURLY:
      case OPEN_FUNNY:
          balance.push(b);
        break;
      case CLOSE_ROUND:
        if(balance.empty() || balance.top() != OPEN_ROUND)
          ok = false;
        else
          balance.pop();
        break;
      case CLOSE_SQUARE:
        if(balance.empty() || balance.top() != OPEN_SQUARE)
          ok = false;
        else
          balance.pop();
        break;
      case CLOSE_ANGLED:
        if(balance.empty() || balance.top() != OPEN_ANGLED)
          ok = false;
        else
          balance.pop();
        break;
      case CLOSE_CURLY:
        if(balance.empty() || balance.top() != OPEN_CURLY)
          ok = false;
        else
          balance.pop();
        break;
      case CLOSE_FUNNY:
        if(balance.empty() || balance.top() != OPEN_FUNNY)
          ok = false;
        else
          balance.pop();
        break;

      };
       
      if(!ok)
        break;
    }

    if(!balance.empty())
      ok = false;

    if(ok)
      printf("YES\n");
    else
      printf("NO %d\n", v);

  }

}
