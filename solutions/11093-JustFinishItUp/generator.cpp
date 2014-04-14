#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
  srand(time(0));

  const int t = atoi(argv[1]);
  const int n = atoi(argv[2]);

  cout << t << endl;

  for(int i = 0; i < t; ++i)
  {
    cout << n << endl;

    cout << rand() % n + 1;

    for(int i = 1; i < n; ++i)
      cout << " " << rand() % n + 1;

    cout << endl;
    
    cout << rand() % n + 1;

    for(int i = 1; i < n; ++i)
      cout << " " << rand() % n + 1;

    cout << endl;
    
  }
  

  
  return 0;
}
