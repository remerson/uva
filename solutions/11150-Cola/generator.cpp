#include <iostream>

using namespace std;

int main()
{
  cout << "char *values[101] = { " << endl; 

  for(int n = 1; n <= 100; ++n)
  {
    int empty = n;
    int drank = 0;

    while(empty > 2)
    {
      empty -= 2;
      ++drank;
    }

    if(empty == 2) ++drank;

    cout << "\"" << drank << "\\n\"," << endl;
  }

  cout << "};" << endl;

  return 0;
}
