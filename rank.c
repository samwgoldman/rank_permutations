#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"

uint64_t rank(uint32_t n, uint32_t k, uint32_t* p);

int main(int argc, char* argv[])
{
  uint32_t n; // length of set
  uint32_t k; // length of permutation
  uint32_t* p; // input permutation (must be length k)
  uint64_t r; // rank
  
  if (argc < 2 || argc > 3)
  {
    printf("Usage: %s n <k>\n", argv[0]);
    return 1;
  }
  
  n = strtoul(argv[1], (char**)NULL, 10);
  
  if (argc == 3)
  {
    k = strtoul(argv[2], (char**)NULL, 10);
  }
  else
  {
    k = n;
  }
  
  if (k > n)
  {
    printf("Error: value of k must be less than or equal to n.\n");
    return 1;
  }
  
  p = read_permutation(k);
  
  r = rank(n, k, p);
  printf("%" PRIu64 "\n", r);
  
  free(p);
  
  return 0;
}

uint64_t rank_inner(uint32_t n, uint32_t k, uint32_t* p, uint32_t* i)
{
  if (k == 1)
    return 0;
  
  int s = p[n - 1];
  size_t size = sizeof(uint32_t);
  swap(&p[n - 1], &p[i[n - 1]], size);
  swap(&i[s], &i[n - 1], size);
  
  return (s + n * rank_inner(n - 1, k - 1, p, i));
}

uint64_t rank(uint32_t n, uint32_t k, uint32_t* p)
{
  uint32_t* i = inverse_permutation(n, p);
  uint64_t r = rank_inner(n, k, p, i);
  free(i);
  return r;
}
