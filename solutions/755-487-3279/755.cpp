#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <iostream>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

void sanitise(string &x)
{
  DEBUG(printf("SANITISE IN x = [%s]\n", x.c_str()));
  for(size_t i = 0; i < x.length(); ++i)
  {
    switch(x[i])
    {
    case '-':
      x.erase(i, 1);
      i--;
      break;
    case 'A':
    case 'B':
    case 'C':
      x[i] = '2'; break;
    case 'D':
    case 'E':
    case 'F':
      x[i] = '3'; break;
    case 'G':
    case 'H':
    case 'I':
      x[i] = '4'; break;
    case 'J':
    case 'K':
    case 'L':
      x[i] = '5'; break;
    case 'M':
    case 'N':
    case 'O':
      x[i] = '6'; break;
    case 'P':
    case 'R':
    case 'S':
      x[i] = '7'; break;
    case 'T':
    case 'U':
    case 'V':
      x[i] = '8'; break;
    case 'W':
    case 'X':
    case 'Y':
      x[i] = '9'; break;
    }
  }

  DEBUG(printf("SANITISE PRE x = [%s]\n", x.c_str()));

  x.insert(3, "-");

  DEBUG(printf("SANITISE OUT x = [%s]\n", x.c_str()));
}

int main()
{
  int tests;
  typedef map<string, int> Numbers;
  string x;
  int n;

  if(scanf("%d\n", &tests));

  for(int t = 0; t < tests; ++t)
  {
    cin >> n;

    Numbers nums;

    for(int i = 0; i < n; ++i)
    {
      cin >> x;
      sanitise(x);

      Numbers::iterator it = nums.find(x);
      if(it == nums.end())
      {
        it = nums.insert(Numbers::value_type(x, 0)).first;
      }
      it->second++;
    }

    Numbers::iterator it = nums.begin();

    bool found = false;

    if(t > 0) printf("\n");

    while(it != nums.end())
    {
      if(it->second > 1)
      {
        printf("%s %d\n", it->first.c_str(), it->second);
        found = true;
      }
      ++it;
    }

    if(!found)
    {
      printf("No duplicates.\n");
    }
  }

  return 0;
}
