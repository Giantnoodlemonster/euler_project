#!/usr/bin/env python3
"""2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26. What is the sum of the digits of the number 2^1000?"""

def string_add(str1, str2):
    """Returns sum of str1 and str2

    Assumes str1 and str2 are base 10 integers.
    Assumes str1 is equal to- or longer than str2"""

    output = ""
    carry_in = 0

    l = len(str1)
    l_diff = l - len(str2)
    if l_diff > 0:
        str2 = "0" * l_diff + str2

    for i in range(l):
        val = int(str1[-(i+1)]) + int(str2[-(i+1)]) + carry_in
        output = str(val % 10) + output
        carry_in = (0 if val < 10 else 1)

    if carry_in == 1:
        output = "1" + output
        
    return output

def string_sum(string):
    output = 0
    for c in string:
        output += int(c)
    return output

def main():
    output = "2"
    for i in range(2,1000+1):
        output = string_add(output, output)
    print(output[:])
    print(string_sum(output))
    exit()


if __name__ == "__main__":
    main()
