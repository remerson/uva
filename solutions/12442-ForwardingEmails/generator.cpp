#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>

using namespace std;

const int MAX_M = 50010;

int main(int argc, char **argv)
{
  const int c = atoi(argv[1]);
  const int m = atoi(argv[2]);

  srand(time(0));

  cout << c << endl;

  int a[MAX_M];
  int b[MAX_M];

  for(int i = 1; i <= m; ++i)
  {
    a[i] = i;
    b[i] = i;
  }

  for(int i = 0; i < c; ++i)
  { 
    random_shuffle(a + 1, a + m + 1);
    random_shuffle(b + 1, b + m + 1);
    
    cout << m << endl;

    for(int i = 1; i <= m; ++i)
    {
      int v = b[i];
      while(v == a[i])
        ++v;
      cout << a[i] << " " << v << endl;
    }

    //cout << values[m] << " " << values[1] << endl;
  }

  cout << endl;
  
  return 0;
}
