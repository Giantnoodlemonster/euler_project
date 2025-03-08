/*
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is
 * 9009 = 91 x 99.
 * Find the largest palindrome made from the product of two 3-digit numbers
 */
#include <stdio.h>

int int_rev(int);

int main(void){
    int save = 0;
    int test_val = 0;
    for(int i = 1; i < 1000; i++){
        for(int j = i + 1; j < 1000; j++){
            test_val = i * j;
            if((test_val == int_rev(test_val)) && (test_val > save))
                save = test_val;
        }
    }

    printf("%i\n", save);
    return 0;
};

int int_rev(int x){
    // Get base 10 power
    int pow = 1;
    int pot = 0;
    while(pow * 10 <= x){
        pow *= 10;
        pot += 1;
    }

    int xr = 0;
    for(int c = 0; c <= pot; c++){
        xr += (x % 10) * pow;
        x = (x - (x % 10)) / 10;
        pow /= 10;
    }

    return xr;
};
