/*
 * Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
 * How many such routes are there through a 20x20 grid?
 */
#include <stdio.h>

#define GRID_HEIGHT 20L
#define GRID_WIDTH 20L
#define STEPS_DOWN GRID_HEIGHT
#define STEPS_OVER GRID_WIDTH
#define STEPS_TOT (STEPS_DOWN + STEPS_OVER)

/*
 * Calculate number of non-zero bits in 'x'
 */
int bitsum(unsigned long int x){
    int c = 0;
    for(int i = 0; (i < STEPS_TOT) && (x != 0); i++){
        c += x & 0b1;
        x >>= 1;
    }
    return c;
};

/*
 * Adds 'c' set bits to 'x', filling in from LSB first
 */
unsigned long int bitfill(unsigned long int x, unsigned long int c){
    unsigned long int bit = 0b1;
    while(c > 0){
        // if bit in 'x' not occupied, add bit
        if(!(x & bit)){
            x += bit;
            c--;
        }
        bit <<= 1;
    }
    return x;
};

/*
 * Remove 'c' set bits from 'x' while still incrementing by adding the complement of the first n least significant bits that include 'c' set bits, + 1
 * Will not guarantee output has 'c' set bits less, but all values between 'x' and output were guaranteed to have less that 'c' set bits fewer than 'x'
 */
unsigned long int bitremove(unsigned long int x, unsigned long int c){
    unsigned long int bit = 0b1;
    int i = 0;
    while(i < c){
        if(bit & x)
            i += 1;
        bit <<= 1;
    }

    x &= ~(bit - 1);
    x += bit;
    return x;
}

int main(void){
    // How many numbers up to (2^STEPS_TOT - 1) have a bit sum of 20?
    unsigned long long int i = (0b1 << ((STEPS_OVER < STEPS_DOWN) ? STEPS_OVER : STEPS_DOWN)) - 1, c = 0, sum, diff;

    while(i < (0b1LL << STEPS_TOT)){
        sum = bitsum(i);

        if(sum == STEPS_OVER)
            c++;

        if(sum < STEPS_OVER)
            i = bitfill(i, STEPS_OVER - sum);
        else if(sum > STEPS_OVER)
            i = bitremove(i, sum - STEPS_OVER);
        else
            i += 1;

    }

    printf("%lli\n", c);
    return 0;
};
