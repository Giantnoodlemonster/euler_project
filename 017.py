#!/usr/bin/env python3
# If the number of 1 to 5 are written out in words: one, two, three, four,
# five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
#
# If all the numbers from 1 to 1000 (one thousand) inclusive were written out
# in words,how many letters would be used?
#
# NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
# fourty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
# letters. The use of "and" when writing out numbers is in compliance with
# British usage.

spellings_sub_20 = [
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"]
spellings_20_to_90 = [
    "twenty",
    "thirty",
    "fourty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"]


def num_to_spelled(i):
    sub_100 = i % 100
    sup_100 = (i - sub_100) // 100
    sub_10 = i % 10

    output = ""
    if sup_100 > 0:
        output = output + spellings_sub_20[sup_100 - 1] + " hundred"
        if sub_100 > 0:
            output = output + " and "

    if 0 < sub_100 < 20:
        output = output + spellings_sub_20[sub_100 - 1]
    elif sub_100 >= 20:
        output = output + spellings_20_to_90[((sub_100 - sub_10) // 10) - 2]
        if sub_10 > 0:
            output = output + "-" + spellings_sub_20[sub_10 - 1]
    return output


def main():
    numbers = ""
    for i in range(1, 1000):
        numbers = numbers + num_to_spelled(i).replace(" ","").replace("-","")
    numbers = numbers + "onethousand"
    print(len(numbers))
    exit()

if __name__ == "__main__":
    main()
