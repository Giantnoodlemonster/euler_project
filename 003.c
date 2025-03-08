/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143?
 */
#include <stdio.h>
#include "tools.h"

#define TEST_VAL 600851475143
int main(void){
    long int test_val = TEST_VAL;
    int i;
    for(i = 3; test_val != 1; i += 2){
        while(!(test_val % i))
            test_val /= i;
    }

    printf("%i\n", i - 2);
    return 0;
};
