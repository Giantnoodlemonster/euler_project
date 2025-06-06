#include "tools.h"
#include <stdbool.h>

/*
 *  Put the first 'n_primes' primes into array 'primes'.
 */
void get_n_primes(int* primes, int n_primes){
    primes[0] = 2;
    primes[1] = 3;
    int c_primes = 2;  // current count of primes

    int test_val;
    for(int i = 2; i < n_primes; i++){
        test_val = primes[i-1] + 2;

        while(!is_prime(primes, c_primes, test_val))
            test_val += 2;

        c_primes++;
        primes[i] = test_val;
    }
};

/*
 * Generate primes up to 'max_val', returns number of primes found 'l_primes'
 */
int get_primes_upto(int* primes, int max_val){
    primes[0] = 2;
    primes[1] = 3;
    int l_primes = 2;

    for(int test_val = 5; test_val <= max_val; test_val += 2){
        if(is_prime(primes, l_primes, test_val)){
            primes[l_primes] = test_val;
            l_primes++;
        }
    }

    return l_primes;
};

/* 
 * Adds prime values up to 'max_val' to array 'primes'
 * Returns new 'primes' length 'l_primes'
 */
int add_primes_upto(int* primes, int l_primes, int max_val){
    for(int test_val = primes[l_primes-1] + 2; test_val <= max_val; test_val += 2){
        if(is_prime(primes, l_primes, test_val)){
            primes[l_primes] = test_val;
            l_primes++;
        }
    }

    return l_primes;
};

/*
 *  Tests 'test_val' for divisibility by values in 'primes'.
 *  Assumes 'primes' is an array of primes up to 'test_val'/2 or more,
 *  'l_primes' is length of 'primes'.
 */
bool is_prime(int* primes, int l_primes, int test_val){
    for(int i = 0; i < l_primes; i++){
        if((test_val % primes[i]) == 0)  // if 'divisible by primes[i]'
            return false;
    }

    return true;
};

/*
 * Convert char to corresponding ASCII integer
 */
int c2i(char c){
    return c - 48;
};

/*
 * Return number of divisors of x
 */
int count_divisors(int x){
    int i,save = 2;
    for(i = 2; i <= x / 2; i++){
        if(!(x % i))
            save += 1;
    }

    return save;
}

/*
 * Return number of divisors of x
 * Uses prime factorization instead of direct factorization
 * Assumes that 'primes' and 'l_primes' are such that all primes up to and including 'x/2' are present
 */
int count_divisors_primef(int x, int* primes, int l_primes){
    int save = 1;
    int e_count = 0;

    // For each prime, save *= (exponent + 1), end when x is completely factorized
    for(int i = 0; (i < l_primes) & (x > 1); i++){
        while(!(x % primes[i])){
            e_count += 1;
            x /= primes[i];
        }
        save *= e_count + 1;
        e_count = 0;
    }

    return save;
}
