#include <iostream>
#include <cstdio>
#include <cmath>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int L_MAX = 64;

int main(int argc, char **argv)
{
  std::ios_base::sync_with_stdio(false);

  int n;
  char c;
  char stack[L_MAX];
  char output[L_MAX];

  const int B_MAX = 8;

  char buffer[B_MAX + 1];

  if(scanf("%d\n", &n));

  DEBUG(printf("N = %d\n", n));

  for(int q = 0; q < n; ++q)
  { 
    DEBUG(printf("CASE %d\n", q));
    stack[0] = 0;
    output[0] = 0;
    while(fgets(buffer, B_MAX, stdin))
    {
      if(buffer[0] == '\n') break;
      const char c = buffer[0];
      DEBUG(printf("READ %c\n", c));
      switch(c)
      {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        output[++output[0]] = c;
        DEBUG(printf("OUT %c\n", c));
        break;
      case '+':
      case '-':
        //while(stack[0] > 0 && (stack[stack[0]] == '*' || stack[stack[0]] == '/'))
        while(stack[0] > 0 && (stack[stack[0]] != '('))
        {
          output[++output[0]] = stack[stack[0]--];
        }
        stack[++stack[0]] = c;
        DEBUG(printf("PUSH %c\n", c));
        break;
      case '*':
      case '/':
        while(stack[0] > 0 && (stack[stack[0]] == '*' || stack[stack[0]] == '/'))
                  //        while(stack[0] > 0 && (stack[stack[0]] != '('))
          output[++output[0]] = stack[stack[0]--];
        stack[++stack[0]] = c;
        DEBUG(printf("PUSH %c\n", c));
        break;
      case '(':
        stack[++stack[0]] = c;
        DEBUG(printf("PUSH %c\n", c));
        break;
      case ')':
        while(stack[0] > 0 && (stack[stack[0]] != '('))
          output[++output[0]] = stack[stack[0]--];
        stack[0]--;
        break;
      default:
        DEBUG(printf("ERROR unhandled operator [%c]\n", c));
      }
      
    }

    while(stack[0] > 0)
        output[++output[0]] = stack[stack[0]--];

    output[++output[0]] = '\0';
   
    if(q>0)
      printf("\n");
    printf("%s\n", &output[1]);
      
  }

  return 0;
}
