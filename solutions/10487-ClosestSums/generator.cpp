#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
  srand(time(0));

  const int n = atoi(argv[1]);
  const int m = atoi(argv[2]);

  cout << n << endl;

  for(int i = 0; i < n; ++i)
    cout << rand() - (INT_MAX / 2) << endl;

  cout << m << endl;

  for(int i = 0; i < m; ++i)
    cout << rand() - (INT_MAX / 2) << endl;
  
  return 0;
}
