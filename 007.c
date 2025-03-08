/*
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, 13, we cansee that the 6th prime is 13.
 * What is the 10 001st prime number?
 */
#include <stdio.h>
#include "tools.h"

int main(void){
    int primes[10001] = {0};
    int n_primes = 10001;

    get_n_primes(primes, n_primes);

    printf("%i\n", primes[n_primes-1]);
    return 0;
};
