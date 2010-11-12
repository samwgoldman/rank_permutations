#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "common.h";

uint32_t* create_identity_permutation(uint32_t n)
{
  uint32_t i;
  uint32_t *p = malloc(n * sizeof(uint32_t));
  for (i = 0; i < n; i++)
    p[i] = i;
  return p;
}

uint32_t* inverse_permutation(uint32_t n, uint32_t* p)
{
  uint32_t i;
  uint32_t* inverse = malloc(n * sizeof(uint32_t));
  for (i = 0; i < n; i++)
    inverse[p[i]] = i;
  return inverse;
}

uint32_t* read_permutation(uint32_t n)
{
  uint32_t* p = malloc(n * sizeof(uint32_t));
  uint32_t i;
  for (i = 0; i < n; i++)
  {
    uint32_t val;
    scanf("%" PRIu32, &val);
    p[i] = val;
  }
  return p;
}

void print_permutation(uint32_t n, uint32_t *p)
{
  uint32_t i;
  for (i = 0; i < n; i++)
    printf("%" PRIu32 "\n", p[i]);
}

void swap(void* restrict a, void* restrict b, size_t size)
{
  void *tmp = malloc(size);
  assert(tmp);
  
  memcpy(tmp, b, size);
  memcpy(b, a, size);
  memcpy(a, tmp, size);
  
  free(tmp);
}
