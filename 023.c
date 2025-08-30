/*
 * A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example,
 * the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 * 
 * A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if the sum
 * exceeds n.
 * 
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of
 * two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be
 * written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even
 * though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than
 * this limit.
 * 
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */
#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include "tools.h"

#define MAX_VAL 28123

int divisor_sum(int x, int *divisors, int limit){
    int count = get_divisors(x, divisors, limit);
    int sum = 0;
    for(int i = 0; i < count; i++)
        sum += divisors[i];
    return sum;
};

int main(void){
    // Find all abundant vals
    int divisors[MAX_VAL], limit = MAX_VAL;
    int ab_vals[MAX_VAL], count = 0;
    for(int test_val = 12; test_val <= MAX_VAL; test_val++){
        if(divisor_sum(test_val, divisors, limit) > test_val){
            ab_vals[count] = test_val;
            count += 1;
        }
    }
    printf("Finished finding abundant values.\n");
    printf("Found %i values.\n", count);
    printf("Largest abundant value is %i.\n", ab_vals[count-1]);
    printf("\n");

    // Generate all possible abundant value sums; for each value generated, put a corresponding 0 in linear array to mark it out
    int mask[MAX_VAL];
    int ab_sum;
    for(int i = 0; i < MAX_VAL; i++){
        mask[i] = i + 1;
    }
    printf("Finished generating initial mask.\n");
    printf("\n");
    for(int i = 0; i < count; i++){
        for(int j = 0; j <= i; j++){
            ab_sum = ab_vals[i] + ab_vals[j];
            if(ab_sum <= MAX_VAL){
                mask[ab_sum - 1] = 0;
            }
            if(ab_sum > MAX_VAL){
                break;
            }
        }
    }
    printf("Finished generating final mask.\n");
    printf("\n");

    // Sum remaining (non-abundant-sum) values
    int sum = 0;
    for(int i = 0; i < MAX_VAL; i++){
        sum += mask[i];
    }
    printf("Finished generating sum.\n");
    printf("\n");

    printf("%i\n", sum);
    return 0;
};
