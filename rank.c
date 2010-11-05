#include <stdio.h>
#include <stdlib.h>
#include "common.h"

// Returns the rank of the permutation p of length n
int rank(int n, int* p);

int main(int argc, char* argv[])
{
  int n = 3;
  
  int* p = create_random_permutation(n);
  
  print_permutation(n, p);
  printf(": %d\n", rank(n, p));
  
  return 0;
}

int rank_inner(int n, int* p, int* i)
{
  if (n == 1)
    return 0;
  
  int s = p[n - 1];
  swap(&p[n - 1], &p[i[n - 1]]);
  swap(&i[s], &i[n - 1]);
  
  return (s + n * rank_inner(n - 1, p, i));
}

int rank(int n, int* p)
{
  int* i = inverse_permutation(n, p);
  int r = rank_inner(n, p, i);
  free(i);
  return r;
}