#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <string>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

int main()
{
  typedef map<string, string> Dictionary;

  Dictionary dict;
  string a, b, buffer;
  int i;

  while(true)
  {
    getline(cin, buffer);

    if(buffer.length() == 0) break;

    while(buffer[i] != ' ') ++i;
    
    a = buffer.substr(0, i);
    b = buffer.substr(i+1, buffer.length() - i);

    DEBUG(printf("a = [%s] b = [%s]\n", a.c_str(), b.c_str()));

    dict.insert(Dictionary::value_type(b, a));
  }

  Dictionary::const_iterator it;

  while(cin.good())
  {
    cin >> a;

    if(!cin.good()) break;

    it = dict.find(a);

    if(it == dict.end()) printf("eh\n");
    else printf("%s\n", it->second.c_str());
  }

  return 0;
}
