/*
 * You are given the following information, but you may prefer to do some research yourself.
 * - 1 Jan 1900 was a Monday.
 * - Thirty days has September,
 *   April, June and November.
 *   All the rest have thirty-one,
 *   Saving February alone,
 *   Which has twenty-eight, rain or shine.
 *   And on leap years, twenty-nine.
 * - A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */
#include <stdio.h>

int main(void){
    int day_counter = 0;
    int DD = 1, MM = 1, YYYY = 1900;
    int SUNDAY = 6;
    int month_len[] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    int is_leap_year = 0;
    int count = 0;

    while(YYYY < 2001){
        if(((day_counter % 7) == SUNDAY) && (DD == 1) && (YYYY >= 1901)){
            count++;
        }

        day_counter++;
        DD++;

        if(!(YYYY % 100) && !(YYYY % 400)){
            is_leap_year = 1;
        }
        else if((YYYY % 100) && !(YYYY % 4)){
            is_leap_year = 1;
        }
        else{
            is_leap_year = 0;
        }

        if(DD > (month_len[MM - 1] + ((MM == 2)?is_leap_year:0))){
            DD = 1;
            MM++;
        }
        if(MM > 12){
            MM = 1;
            YYYY++;
        };
    };

    printf("%i\n", count);
    return 0;
};
