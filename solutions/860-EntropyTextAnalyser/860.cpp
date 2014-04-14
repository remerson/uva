#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <map>
#include <string>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const char end_text[] = "****END_OF_TEXT****\n";
const char end_input[] = "****END_OF_INPUT****\n";

const int T_MAX = 24;
const int B_MAX = 131072;

int main()
{
  typedef map<string, int> WordsMap;

  char buffer[B_MAX];
  buffer[0] = '\0';

  WordsMap words;

  while(fgets(&buffer[0], B_MAX, stdin))
  {
    DEBUG(printf("BUFFER: %s\n", &buffer[0]));
    
    

    if(strcmp(&end_input[0], &buffer[0]) == 0) break;
    
    if(strcmp(&end_text[0], &buffer[0]) == 0)
    {
      int lambda = 0;

      WordsMap::const_iterator it = words.begin();
      const WordsMap::const_iterator ie = words.end();

      while(it != ie)
      {
        lambda += it->second;
        ++it;
      }

      const double logLambda = log10(static_cast<double>(lambda));

      it = words.begin();
      
      double e = 0.0;

      while(it != ie)
      {
        const double pi = static_cast<double>(it->second);

        e += pi * (logLambda - log10(pi));

        ++it;
      }

      e *= (1.0 / static_cast<double>(lambda));

      const double rel = (e / logLambda) * 100.0;

      double relflr = floor(rel);

      if ((rel - relflr) >= 0.5) relflr += 1.0;

      const int erel = static_cast<int>(relflr);

      printf("%d %.1f %d\n", lambda, e, erel);

      words.clear();
      continue;
    }

    char *s = &buffer[0];
    char *b = &buffer[0];

    while(*b != '\0')
    {
      switch(*b)
      {
      case ' ':
      case '\t':
      case '\n':
      case '.':
      case ',':
      case ':':
      case ';':
      case '!':
      case '?':
      case '"':
      case '(':
      case ')':
        {
          *b = '\0';
          const string key(s);
          if (key.length() > 0)
          {
            const WordsMap::iterator it = words.find(key);
            DEBUG(printf("WORD: %s\n", key.c_str()));
            if(it != words.end()) ++(it->second);
            else words.insert(WordsMap::value_type(key, 1));
          }
          ++b;
          s = b;
        }
        break;
      default:
        *b = toupper(*b);
        ++b;
      }
    }
  }

  return 0;
}
