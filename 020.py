#!/usr/bin/env python3
# n! means n * (n-1) * ... * 3 * 2 * 1.
# For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
# and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
# Find the sum of the digits in the number 100!

def str_val_mult(s1, s2):
    output = 0
    dec1 = 1
    for i1 in [int(c) for c in s1[::-1]]:
        dec2 = 1
        for i2 in [int(c) for c in s2[::-1]]:
            output += i1 * dec1 * i2 * dec2
            dec2 *= 10
        dec1 *= 10
    return output

def digit_sum_str(x):
    return sum([int(i) for i in x])

def main():
    s1 = "1"
    for i in range(1, 101):
        s2 = str(i)
        s1 = str(str_val_mult(s1, s2))
    print(digit_sum_str(s1))
    exit()

if __name__ == "__main__":
    main()
