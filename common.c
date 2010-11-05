#include <stdlib.h>
#include <stdio.h>
#include "common.h";

int* create_identity_permutation(int n)
{
  int i;
  int *p = malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    p[i] = i;
  return p;
}

int* create_random_permutation(int n)
{
  int i;
  int* p = create_identity_permutation(n);
  for (i = n - 1; i > 0; i--)
  {
    int j = arc4random() % (i + 1);
    swap(&p[i], &p[j]);
  }
  return p;
}

int* inverse_permutation(int n, int* p)
{
  int i;
  int* inverse = malloc(n * sizeof(n));
  for (i = 0; i < n; i++)
    inverse[p[i]] = i;
  return inverse;
}

void print_permutation(int n, int *p)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", p[i]);
}

int factorial(int n)
{
  if (n <= 1)
    return 1;
  else
    return n * factorial(n - 1);
}

void swap(int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
