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
  {
    const int a = rand() % 100 + 1;
    const int b = rand() % 100 + 1;
    const int k = rand() % 1000 + 1;

    if((rand() % 5 + 1) == 1)
      cout << a << " " << a + b << endl;
    else
      cout << a << " " << a * b * k << endl;
  }

  
  return 0;
}
