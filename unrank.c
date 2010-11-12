#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "common.h"

uint32_t* unrank(uint32_t n, uint32_t k, uint32_t r, uint32_t* p);

int main(int argc, char* argv[])
{
  // input
  uint64_t r; // desired rank
  uint32_t n; // length of set
  uint32_t k; // length of permutation
  
  uint32_t* p; // identity permutation
  uint32_t* unranked; // unranked permutation
  
  if (argc < 3 || argc > 4)
  {
    printf("Usage: %s r n <k>\n", argv[0]);
    return 1;
  }
  
  r = strtoull(argv[1], (char**)NULL, 10);
  n = strtoul(argv[2], (char**)NULL, 10);
  
  if (argc == 4)
  {
    k = strtoul(argv[3], (char**)NULL, 10);
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
  
  p = create_identity_permutation(n);
  unranked = unrank(n, k, r, p);
    
  print_permutation(k, unranked);
    
  free(p);
  
  return 0;
}

uint32_t* unrank_inner(uint32_t n, uint32_t k, uint32_t r, uint32_t* p)
{
  if (k > 0)
  {
    swap(&p[n - 1], &p[r % n], sizeof(uint32_t));
    unrank(n - 1, k - 1, r / n, p);
  }
  return p;
}

uint32_t* unrank(uint32_t n, uint32_t k, uint32_t r, uint32_t* p)
{
  return unrank_inner(n, k, r, p) + (n - k);
}
