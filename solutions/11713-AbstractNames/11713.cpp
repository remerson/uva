#include <cstdio>
#include <cstring>


#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

int C_MAX = 32;

bool isvowel(char c)
{
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
  int tests;

  char s1[C_MAX];
  char s2[C_MAX];

  if(scanf("%d\n", &tests));

  for(int t = 0; t < tests; ++t)
  {
    fgets(&s1[0], C_MAX, stdin);
    fgets(&s2[0], C_MAX, stdin);

    const int len1 = strlen(s1);
    const int len2 = strlen(s2);

    DEBUG(printf("s1=[%s] s2=[%s]\n", &s1[0], &s2[0]));

    if(len1 != len2)
    {
      printf("No\n");
      DEBUG(printf("No (len doesn't match)\n"));
      continue;
    }
    else
    {
      bool ok = true;

      for(int i = 0; i < len1; ++i)
      {
        bool v1 = isvowel(s1[i]);
        bool v2 = isvowel(s2[i]);

        if( (v1 && !v2) || (!v1 && v2) || (!v1 && !v2 && s1[i] != s2[i]) ) 
        {
          DEBUG(printf("v1 = %s v2 = %s\n", v1?"true":"false", v2?"true":"false"));
          ok = false;
          break;
        }        
      }

      if(ok) printf("Yes\n");
      else printf("No\n");
    }
  
  }

  return 0;
}
