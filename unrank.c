#include <stdio.h>
#include "common.h"

int* unrank(int n, int r, int* p);

int main(int argc, char* argv[])
{
  int n = 3;
  
  int r;
  for (r = 0; r < factorial(n); r++)
  {
    int* p = create_identity_permutation(n);
    int* unranked = unrank(n, r, p);
    
    printf("%d: ", r);
    print_permutation(n, unranked);
    printf("\n");
    
    free(p);
  }
  
  return 0;
}

int* unrank(int n, int r, int* p)
{
  if (n > 0)
  {
    swap(&p[n - 1], &p[r % n]);
    unrank(n - 1, r / n, p);
  }
  return p;
}