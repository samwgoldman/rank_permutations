#include <stdint.h>

// Creates the identity permutation of length n
uint32_t* create_identity_permutation(uint32_t n);

// Creates a random permutation of length n
uint32_t* create_random_permutation(uint32_t n);

// Creates and returns the inverse of the permutation p of length n
uint32_t* inverse_permutation(uint32_t n, uint32_t *p);

// Calculates the number of permutations of length k in the set n
uint64_t num_permutations(uint32_t n, uint32_t k);

// Read the permutation p of length n
uint32_t* read_permutation(uint32_t n);

// Prints the permutation p of length n
void print_permutation(uint32_t n, uint32_t *p);

uint64_t factorial(uint64_t n);

void swap(void* a, void* b, size_t size);