#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <string>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

int main()
{
  typedef set<string> IgnoreSet;
  IgnoreSet ignores;

  typedef multimap<string, string> TitleMap;
  TitleMap titles;

  while(true)
  {
    string word;

    cin >> word;

    if(word == "::") break;

    ignores.insert(word);
    DEBUG(printf("IGNORE [%s]\n", word.c_str()));
  }

  while(cin.good())
  {
    string title;
    getline(cin, title);
    DEBUG(printf("TITLE [%s]\n", title.c_str()));
    transform(title.begin(), title.end(), title.begin(), ::tolower);
    DEBUG(printf("TITLE [%s]\n", title.c_str()));
    if(title.empty()) continue;
    size_t ws = 0, we = 0;
    do
    {
      we = title.find_first_of(' ', ws);
      if(we == string::npos) 
        we = title.length();
      string word = title.substr(ws, (we - ws));
      DEBUG(printf("ws = %d we = %d word [%s]\n", ws, we, word.c_str()));
      if(ignores.find(word) == ignores.end() && we > ws)
      {
        transform(title.begin() + ws, title.begin() + we, title.begin() + ws, ::toupper);
        DEBUG(printf("MATCH/INSERT word[%s] -> title [%s]", title.c_str()));
        titles.insert(TitleMap::value_type(word, title));
        transform(title.begin() + ws, title.begin() + we, title.begin() + ws, ::tolower);
      }
      ws = we + 1;
    }
    while(we != string::npos && ws < title.length());
  }

  TitleMap::const_iterator it = titles.begin();
  const TitleMap::const_iterator ie = titles.end();
  while(it != ie)
  {
    cout << it->second << endl;
    ++it;
  }

  return 0;
}
