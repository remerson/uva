#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string>
#include <set>

using namespace std;

void generate_string(string &s)
{
  s.clear();

  for(int i = 0; i < 20; ++i)
    s.push_back((rand() % 26) + 65);
}

int main(int argc, char **argv)
{
  srand(time(0));

  const int d = atoi(argv[1]);
  const int q = atoi(argv[2]);

  cout << 2 << endl;

  // non-overlapping
  {
    cout << d << endl;
    
    typedef set<string> StringSet;
    
    StringSet names;
    
    string n;
    
    for(int i = 0; i < d; ++i)
    {
      do
      {
        generate_string(n);
      } while(names.find(n) != names.end());
      
      names.insert(n);
    
      cout << n << " " << 1 + i * 100 << " " << (i + 1) * 100 << endl;
    }
    
    const int max_p = min(1000000, (d + 1) * 200);
    
    cout << q << endl;
    
    for(int i = 0; i < q; ++i)
    {
      cout << rand() % max_p << endl;
    }
  }
    
  // overlapping
  {
    cout << d << endl;

    typedef set<string> StringSet;

    StringSet names;
    
    string n;
    
    int min_l = 1000000, max_h = 0;

    for(int i = 0; i < d; ++i)
    {
      do
      {
        generate_string(n);
      } while(names.find(n) != names.end());
      
      names.insert(n);

      const int w = rand() % 100 + 1;
      const int b = rand() % 999900;

      const int l = (b - w);
      const int h = b;

      if(l < min_l)
        min_l = l;

      if(h > max_h)
        max_h = h;
      
      cout << n << " " << b - w << " " << b << endl;
    }
    
    const int max_p = min(1000000, (d + 1) * 200);
    
    cout << q << endl;
    
    for(int i = 0; i < q; ++i)
    {
      cout << rand() % (max_h - min_l) + min_l << endl;
    }
  }
    
  
  return 0;
}
