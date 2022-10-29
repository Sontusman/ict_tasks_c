#include <stdio.h>
#include <stdlib.h>
#define P 0
int main()
{
#if P==1
  printf("Hello, hell!");
#elif P==2
  printf("Hello, paradise!");
#else
  printf("Hello, world!");
#endif
  getchar();
  return 0;
}