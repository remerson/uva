#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <sstream>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int MAX_B = 8;
const int MAX_Z = 26;

int main()
{
  map<string, int> values;

  char buffer[MAX_B];

  {
    int c = 0;
    
    ostringstream buffer;
    
    for(int i = 1; i <= 26; ++i)
    {
      buffer.str("");
      buffer << static_cast<char>(i + 96);
      values.insert(map<string, int>::value_type(buffer.str(), ++c));
    }
    
    for(int i = 1; i <= 26; ++i)
    {
      for(int j = (i + 1); j <= 26; ++j)
      {
        buffer.str("");
        buffer << static_cast<char>(i + 96);
        buffer << static_cast<char>(j + 96);
        values.insert(map<string, int>::value_type(buffer.str(), ++c));
      }
    }

    for(int i = 1; i <= 26; ++i)
    {
      for(int j = (i + 1); j <= 26; ++j)
      {
        for(int k = (j + 1); k <= 26; ++k)
        {
          buffer.str("");
          buffer << static_cast<char>(i + 96);
          buffer << static_cast<char>(j + 96);
          buffer << static_cast<char>(k + 96);
          values.insert(map<string, int>::value_type(buffer.str(), ++c));
        }
      }
    }

    for(int i = 1; i <= 26; ++i)
    {
      for(int j = (i + 1); j <= 26; ++j)
      {
        for(int k = (j + 1); k <= 26; ++k)
        {
          for(int l = (k + 1); l <= 26; ++l)
          {
            buffer.str("");
            buffer << static_cast<char>(i + 96);
            buffer << static_cast<char>(j + 96);
            buffer << static_cast<char>(k + 96);
            buffer << static_cast<char>(l + 96);
            values.insert(map<string, int>::value_type(buffer.str(), ++c));
          }
        }
      }
    }

    for(int i = 1; i <= 26; ++i)
      {
        for(int j = (i + 1); j <= 26; ++j)
          {
            for(int k = (j + 1); k <= 26; ++k)
              {
                for(int l = (k + 1); l <= 26; ++l)
                  {
                    for(int m = (l + 1); m <= 26; ++m)
                      {
                        buffer.str("");
                        buffer << static_cast<char>(i + 96);
                        buffer << static_cast<char>(j + 96);
                        buffer << static_cast<char>(k + 96);
                        buffer << static_cast<char>(l + 96);
                        buffer << static_cast<char>(m + 96);
                        values.insert(map<string, int>::value_type(buffer.str(), ++c));
                      }
                  }
              }
          }
      }
    
  }

  while(fgets(&buffer[0], MAX_B, stdin))
  {
    size_t len = strlen(buffer);
    --len;
    buffer[len] = '\0';

    int r = 0;

    string s(&buffer[0]);
    DEBUG(printf("len = %d s = [%s]\n", len, s.c_str()));
 

    map<string, int>::const_iterator it = values.find(s);

    if(it != values.end())
      r = it->second;

    // map<string, int>::const_iterator is = values.begin();
    // const map<string, int>::const_iterator ie = values.end();
    // DEBUG(printf("values size = %d\n", values.size()));
    // while(is != ie)
    // {
    //   printf("values: s = %s, i = %d\n", is->first.c_str(), is->second);
    //   ++is;
    // }

    printf("%d\n", r);
  }

  return 0;
}
