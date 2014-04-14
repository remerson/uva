#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

const int MAX_N = 1000000;

int main(int argc, char **argv)
{
  srand(time(0));

  const int k = atoi(argv[1]);
  const int nmax = atoi(argv[2]);
  const int mmax = atoi(argv[3]);

  for(int v = 0; v < k; ++v)
  {
    const int n = rand() % nmax + 1;
    const int m = rand() % mmax + 1;
    
    cout << n << " " << m << endl;

  
    for(int i = 0; i < n; ++i)
    {
      const int a = rand() % MAX_N + 1;
      int b = a;
      do
        {
          b = a + rand() % 100 + 1;
        } while(a > b);
      cout << (a % MAX_N) << " " << (b % MAX_N) << endl;
    }
    
    for(int i = 0; i < m; ++i)
    {
      const int a = rand() % + 1;
      int b = a;
      do
      {
        b = a + rand() % 10 + 1;
      } while(a > b);
      const int c = rand() % (MAX_N / 100) + 1;
      cout << (a % MAX_N) << " " << (b % MAX_N) << " " << c << endl;
    }
  }
  cout << 0 << " " << 0 << endl;

  
  return 0;
}
