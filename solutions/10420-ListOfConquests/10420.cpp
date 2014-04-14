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

const int B_MAX = 128;

using namespace std;

int main()
{
  typedef map<string, int> ValueMap;

  ValueMap values;

  int lines;

  scanf("%d\n", &lines);

  char buffer[B_MAX];

  for(int l = 0; l < lines; ++l)
  {
    fgets(&buffer[0], B_MAX, stdin);

    int i = 0;

    while(buffer[i] != ' ' && buffer[i] != '\n') ++i;

    buffer[i] = '\0';

    string country(buffer);

    ValueMap::iterator it = values.find(country);

    if(it == values.end())
    {
      it = values.insert(ValueMap::value_type(country, 0)).first;
    }

    it->second++;
  }

  ValueMap::const_iterator it = values.begin();

  while(it != values.end())
  {
    printf("%s %d\n", it->first.c_str(), it->second);
    ++it;
  }

  return 0;
}
