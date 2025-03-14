/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */
#include <stdio.h>

#define MAX_VAL 1000
int main(void){
    int sum = 0;
    for(int i = 1; i < MAX_VAL; i++){
        if(!(i % 3) || !(i % 5))
            sum += i;
    }

    printf("%i\n", sum);
    return 0;
};
