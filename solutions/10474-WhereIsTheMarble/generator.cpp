#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
  srand(time(0));

  const int t = atoi(argv[1]);
  const int n_max = atoi(argv[2]);
  const int q_max = atoi(argv[3]);

  for(int s = 0; s < t; ++s)
  {
    const int n = rand() % n_max + 1;
    const int q = rand() % q_max + 1;

    cout << n << " " << q << endl;
    
    for(int i = 0; i < n; ++i)
      cout << rand() % 10000 + 1 << endl;

    for(int i = 0; i < q; ++i)
      cout << rand() % 10000 + 1 << endl;
  }
  
  return 0;
}
