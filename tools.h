#ifndef TOOLS_H
#define TOOLS_H

#include <stdbool.h>

void get_n_primes(int*, int);
int get_primes_upto(int*, int);
int add_primes_upto(int*, int, int);
bool is_prime(int*, int, int);
int c2i(char);
int count_divisors(int);
int get_divisors(int, int*, int);
int count_divisors_primef(int, int*, int);
int tri_num(int, int);

#endif
