#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

const size_t S_MAX = 32;
const size_t L_MAX = 64;

using namespace std;

struct record
{
  char title[S_MAX];
  char first[S_MAX];
  char last[S_MAX];
  char department[L_MAX];
  char address[L_MAX];
  char home[L_MAX];
  char work[L_MAX];
  char box[S_MAX];
};

const size_t B_MAX = 8 * L_MAX;

int main(int argc, char **argv)
{
  ios_base::sync_with_stdio(false);

  int d;

  if(scanf("%d\n", &d));

  typedef map<string, record> book;

  char buffer[B_MAX + 1];

  char department[L_MAX + 1];
  department[0] = 0;

  book all;

  for(int t = 0; t < d; ++t)
  {
    while(char *b = fgets(buffer, B_MAX, stdin))
    {
      DEBUG(printf("buffer = [%s]\n", b));
      if(*b == '\n' || *b == 0)
      {
        department[0] = 0;
        break;
      }
      if(department[0] == 0)
      {
        strncpy(department, buffer, L_MAX);
        const size_t len = strlen(department);
        department[len - 1] = '\0';
        DEBUG(printf("SET department = [%s]\n", department));
      }
      else
      {
        record r;
        strncpy(r.department, department, L_MAX);
        sscanf(buffer, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
               &r.title[0], &r.first[0], &r.last[0],
               &r.address[0], &r.home[0], &r.work[0], &r.box[0]);
        string key(r.last);
        DEBUG(printf("INSERT %s -> (%s,%s,%s,%s,%s,%s,%s,%s)\n",
                     key.c_str(), r.title, r.first, r.last,
                     r.department,
                     r.address, r.home, r.work, r.box));
        all.insert(book::value_type(key, r));
      }
    }
  }

  book::const_iterator it = all.begin();
  const book::const_iterator ie = all.end();

  while(it != ie)
  {
    printf("----------------------------------------\n");
    const record &r = it->second;
    printf("%s %s %s\n", r.title, r.first, r.last);
    printf("%s\n", r.address);
    printf("Department: %s\n", r.department);
    printf("Home Phone: %s\n", r.home);
    printf("Work Phone: %s\n", r.work);
    printf("Campus Box: %s\n", r.box);

    ++it;
  }

  return 0;
}
