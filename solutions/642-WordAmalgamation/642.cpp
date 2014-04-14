#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <set>
#include <string>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const string term = "XXXXXX";

int main()
{
  typedef set<string> Words;
  string x = "";
  Words words[7];

  // Hold vector[6] of set<string> instead of multimap 
  // same algo below will then work

  while(true)
  {
    cin >> x;
    if(x == term) break;
    words[x.length()].insert(x);
    DEBUG(printf("ADDED %d -> %s\n", x.length(), x.c_str()));
  }

  while(true)
  {
    cin >> x;
    if(x == term) break;
    DEBUG(printf("CHECK %s\n", x.c_str()));
    
    bool matched = false;

    if(x.length() <= 6 && x.length() >= 1)
    {
      Words::const_iterator s = words[x.length()].begin();
      Words::const_iterator e = words[x.length()].end();
      
      while(s != e)
      {
        string check = *s;
        size_t p = 0;

        DEBUG(printf("TRY %s\n", check.c_str()));
        
        if(check.length() == x.length())
        {
          for(size_t i = 0; i < x.length(); ++i)
          {
            p = check.find(x[i]);
            
            if(p == string::npos) break;
            
            DEBUG(printf("check = [%s] i = %d x[i] = %c p = %d\n", check.c_str(), i, x[i], p));
            
            check.erase(p, 1);
          }
          
          if(check.length() == 0)
          {
            matched = true;
            cout << *s << endl;
          }
        }

        ++s;
      }
    }

    if(!matched) printf("NOT A VALID WORD\n");
    printf("******\n");
  }

  return 0;
}
