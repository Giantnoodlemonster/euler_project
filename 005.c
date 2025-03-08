/*
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */
#include <stdio.h>

int main(void){
    int i,j;

    int factors[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int f_len = 20;

    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    int p_len = 8;

    int saves[p_len];
    for(int i = 0; i < p_len; i++)
        saves[i] = 1;

    int test_val;
    int p_count;
    for(i = 0; i < f_len; i++){
        test_val = factors[i];
        for(j = 0; j < p_len; j++){
            p_count = 0;
            while(!(test_val % primes[j])){
                test_val /= primes[j];
                p_count++;
            }
            if(saves[j] < p_count)
                saves[j] = p_count;
        }
    };

    int save = 1;
    for(i = 0; i < p_len; i++){
        for(j = 0; j < saves[i]; j++)
            save *= primes[i];
    }

    printf("%i\n", save);
    return 0;
};
