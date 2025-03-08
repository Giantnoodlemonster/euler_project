/*
 * The sum of the squares of the first ten natural numbers is,
 *   1^2 + 2^2 + ... + 10^2 = 385.
 * The square of the sum of the first ten natural numbers is,
 *   (1 + 2 + ... + 10)^2 = 55^2 = 3025.
 * Hence the difference between the sum of the suqres of the first ten natural numbers and the square of the sum is
 * 3025 - 385 = 2640.
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */
#include <stdio.h>
#include <limits.h>

int main(void){
    int i;

    int sum_squares = 0;
    for(i = 1; i <= 100; i++)
        sum_squares += i*i;

    int squared_sum = 0;
    for(i = 1; i <= 100; i++)
        squared_sum += i;
    squared_sum *= squared_sum;

    int diff = squared_sum - sum_squares;
    printf("%i\n", diff);
    return 0;
};
