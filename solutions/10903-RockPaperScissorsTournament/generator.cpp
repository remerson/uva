#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

const char *rps()
{
  switch(rand() % 3)
  {
  case 0:
    return "rock";
  case 1:
    return "paper";
  case 2:
    return "scissors";
  }
}

int main(int argc, char **argv)
{
  srand(time(0));

  const int t = atoi(argv[1]);

  for(int i = 0; i < t; ++i)
  {
    const int n = atoi(argv[2]);
    const int k = atoi(argv[3]);
    
    cout << n << " " << k << endl;
   
    for(int p = 0; p < k; ++p)
    {
      for(int a = 1; a <= n; ++a)
        for(int b = a; b <= n; ++b)
          if(a != b)
            cout << a << " "<< rps() << " " << b << " " << rps() << endl;
    }
  }

  cout << "0" << endl;
  
  return 0;
}
