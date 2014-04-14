#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
  vector<int> values;

  for(int i = 2; i <= 1299709; ++i)
    values.push_back(i);

  random_shuffle(values.begin(), values.end());

  for(int i = 0; i < values.size(); ++i)
    cout << values[i] << endl;

  return 0;
}
