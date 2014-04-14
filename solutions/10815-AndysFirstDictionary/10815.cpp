#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int L_MAX = 512;

int main()
{
  char buffer[L_MAX];

  typedef set<string> Dict;

  Dict dict;

  while(fgets(&buffer[0], L_MAX, stdin) != 0)
  {
    int c = 0;
    int s = 0;

    DEBUG(printf("buffer = [%s]\n", buffer));
    
    while(true)
    {
      if(buffer[c] == '\0') break;

      if(islower(buffer[c]) || isupper(buffer[c])) ++c;
      else
      {
        buffer[c] = '\0';
        string word(&buffer[s]);
        s = ++c;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        DEBUG(printf("c = %d s = %d word = [%s]\n", c, s, word.c_str()));
        if(word.length() > 0) dict.insert(word);
        //++c;
      }
    }

  }

  copy(dict.begin(), dict.end(), ostream_iterator<string>(cout, "\n"));

  return 0;
}
