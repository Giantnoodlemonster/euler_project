/*
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 *   a^2 + b^2 = c^2.
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * There exists exactly one Pythagorean tripplet for which a + b + c = 1000.
 * Find the product a*b*c.
 */
#include <stdio.h>

int main(void){
    int a,b,c,flag = 0;
    for(b = 1e3; b > 0; b--){
        for(a = b - 1; a > 0; a--){
            if((1000 * (a + b) - a * b) == 5e5)
                flag = 1;
            if(flag)
                break;
        }
        if(flag)
            break;
    }

    c = 1000 - a - b;
    printf("%i\n", a*b*c);
    return 0;
};
