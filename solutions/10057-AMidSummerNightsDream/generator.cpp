#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
  srand(time(0));

  const int t = atoi(argv[1]);

  cout << t << endl;

  for(int i = 0; i < t; ++i)
    cout << rand() % 65535 + 1 << endl;
  
  return 0;
}
