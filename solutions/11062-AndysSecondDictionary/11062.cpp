#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <bitset>
#include <set>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t B_MAX = 1024 * 1024;

char word[B_MAX];
typedef set<string> Words;
Words words;

void add_word(char *w)
{
  DEBUG(printf("add_word1 [%s]\n", w));

  if(*w == '\0') return;

  string s;

  while(*w != '\0')
  {
    if(isalpha(*w) || isdigit(*w) || *w == '-') 
    {
      s.push_back(tolower(*w));
    }
    ++w;
  }

  DEBUG(printf("add_word [%s]\n", s.c_str()));
  words.insert(Words::value_type(s));
}

int main()
{
  char buffer[B_MAX];
  char *w = word;
  char *b;
  bool keep = false;

  while(b = fgets(buffer, B_MAX - 1, stdin))
  {
    DEBUG(printf("BUFFER [%s] keep? %s\n", buffer, (keep ? "yes" : "no")));
    keep = false;
    while(*b != '\n')
    {
      DEBUG(printf("b = %c\n", *b));
      // if(!isalpha(*b))
//       {
//         *w = '\0';
//         add_word(word);
//         keep = false;
//         w = word;
//         ++b;
//       }
      if(*b == '-')
      {
        if(*(b + 1) == '\n')
        {
          keep = true;
          ++b;
        }
        else
        {
          *w = *b;
          ++w;
          ++b;
        }
      }
      else if(isalpha(*b) || *b == '-')
      {
        *w = tolower(*b);
        DEBUG(printf("COPY %c\n", *w));
        ++w;
        ++b;
      }
      else if(!isalpha(*b))
      {
        *w = '\0';
        add_word(word);
        keep = false;
        w = word;
        ++b;
      }
      else
        ++b;
    }

    if(!keep)
    {
      *w = '\0';
      add_word(word);
      keep = false;
      w = word;
    }
  }

  Words::const_iterator it = words.begin();
  const Words::const_iterator ie = words.end();

  while(it != ie)
  {
    printf("%s\n", it->c_str());
    ++it;
  }

  return 0;
}
