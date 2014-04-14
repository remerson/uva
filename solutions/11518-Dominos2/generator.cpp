#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
  srand(time(0));

  const int t = atoi(argv[1]);
  const int max_n = atoi(argv[2]);
  const int max_m = atoi(argv[3]);
  const int max_l = atoi(argv[4]);

  cout << t << endl;

  for(int s = 0; s < t; ++s)
  {
    const int n = rand() % max_n + 1;
    const int m = rand() % max_m + 1;
    const int l = rand() % max_l + 1;

    cout << n << " " << m << " " << l << endl;
    
    for(int i = 0; i < m; ++i)
    {
      const int a = rand() % n + 1;
      int b = rand() % n + 1;
      while(b == a)
        b = rand() % n + 1;
      cout << a << " " << b << endl;
    }

    for(int i = 0; i < l; ++i)
    {
      const int a = rand() % n + 1;
      cout << a << endl;
    }
  }


  
  return 0;
}
