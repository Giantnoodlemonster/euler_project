/*
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */
#include <stdio.h>
#include "tools.h"

int main(void){
    int primes[1000000], l_primes;
    l_primes = get_primes_upto(primes, 2e6);

    int i;
    long int save = 0;
    for(i = 0; i < l_primes; i++)
        save += primes[i];

    printf("%li\n", save);
    return 0;
};
