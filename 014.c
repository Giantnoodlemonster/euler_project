/*
 * The following iterative sequence is defined for the set of positive integers:
 *   n -> n/2 (n is even)
 *   n -> 3n + 1 (n is odd)
 * Using the rule above and starting with 13, w generate the following sequence:
 *   13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 * It can be seen that this sequence (starting at 13 and finishing at 1 contains 10 terms.
 * Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */
#include <stdio.h>

/* 
 * Returns length of Collatz series for start value 'x'
 */
int collatz(unsigned int x){
    int c = 1;

    while(x != 1){
        x = (x % 2) ? (3*x + 1) : (x>>1);
        c++;
    }

    return c;
};

int main(void){
    unsigned int save_l = 1, save_i = 1, l;

    for(unsigned int i = 2; i <= 1000000; i++){
        l = collatz(i);
        if(l > save_l){
            save_l = l;
            save_i = i;
        }
    }

    printf("%i\n", save_i);
    return 0;
};
