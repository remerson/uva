#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <bitset>
#include <list>
#include <iterator>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t B_MAX = 1024 * 100;

int main()
{
  char buffer[B_MAX];

  std::ios_base::sync_with_stdio(false);

  while(fgets(buffer, B_MAX, stdin))
  //while(gets(buffer))
  {
    //const size_t len = strlen(buffer);

    deque<char> output;
    //output.reserve(len);

    deque<char>::iterator it = output.begin();
    bool append = true;

    int i = 0;
    bool has_input = true;

    //for(int i = 0; i < buffer.length(); ++i)
    while(has_input)
    {
      switch(buffer[i])
      {
      case '[':
        it = output.begin();
        append = false;
        break;
      case ']':
        append = true;
        break;
      case '\n':
        //case '\0':
        has_input = false;
        break;
      default:
        if(append)
        {
          output.push_back(buffer[i]);
          DEBUG(cout << "APPEND " << buffer[i] << " output: ");
          DEBUG(copy(output.begin(), output.end(), ostream_iterator<char>(cout)));
        }
        else
        {
          it = output.insert(it, buffer[i]);
          DEBUG(cout << "INSERT " << buffer[i] << " output: ");
          DEBUG(copy(output.begin(), output.end(), ostream_iterator<char>(cout)));
          ++it;
        }
      }
      ++i;
    }

    it = output.begin();
    const deque<char>::const_iterator ie = output.end();
    int j = 0;
    while(it != ie) { buffer[j++] = *it++; }
    write(1, buffer, output.size());
    char c = '\n';
    write(1, &c, 1);
  }

  return 0;
}
