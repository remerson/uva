#include <cstdio>

const int M_MAX = 12;

int main()
{
  int problems;
  int test = 0;

  int bank[M_MAX + 1];
  int wanted[M_MAX + 1];

  while(scanf("%d", &problems) != EOF)
  {
    if(problems < 0 || problems > 100) break;

    for(int i = 1; i <= M_MAX; ++i) scanf("%d", &bank[i]);
    for(int i = 1; i <= M_MAX; ++i) scanf("%d", &wanted[i]);

    printf("Case %d:\n", ++test);

    for(int i = 1; i <= M_MAX; ++i)
    {
      if(problems >= wanted[i]) 
      {
        printf("No problem! :D\n");
        problems -= wanted[i];
      }
      else 
        printf("No problem. :(\n");

      problems += bank[i];
     
    }

  }

  return 0;
}
