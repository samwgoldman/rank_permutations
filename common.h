#include <stdint.h>

// Creates the identity permutation of length n
uint32_t* create_identity_permutation(uint32_t n);

// Creates and returns the inverse of the permutation p of length n
uint32_t* inverse_permutation(uint32_t n, uint32_t *p);

// Read the permutation p of length n
uint32_t* read_permutation(uint32_t n);

// Prints the permutation p of length n
void print_permutation(uint32_t n, uint32_t *p);

void swap(void* a, void* b, size_t size);
