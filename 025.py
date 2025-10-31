#!/usr/bin/env python3
# The Fibonacci sequence is defined by the recurance relation:
#   F(n) = F(n-1) + F(n-2), where F(1) = 1 and F(2) = 1.
# Hence the first 12 terms will be:
#   F(1) = 1
#   F(2) = 1
#   F(3) = 2
#   F(4) = 3
#   F(5) = 5
#   F(6) = 8
#   F(7) = 13
#   F(8) = 21
#   F(9) = 34
#   F(10) = 55
#   F(11) = 89
#   F(12) = 144
# The 12th term, F(12), is the first term to contain three digits.
# What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

def str_add(s1, s2):
    assert s1 != ""
    assert s2 != ""
    assert all([c.isdigit() for c in s1])
    assert all([c.isdigit() for c in s2])

    l1 = len(s1)
    l2 = len(s2)
    if(l1 < l2):
        s1 = "0" * (l2 - l1) + s1
    elif(l2 < l1):
        s2 = "0" * (l1 - l2) + s2

    output = ""
    dummy = ""
    carry = 0
    for c1,c2 in zip(s1[::-1],s2[::-1]):
        dummy = int(c1) + int(c2) + carry
        carry = 1 if dummy >= 10 else 0
        output = str(dummy)[-1] + output
    if carry > 0:
        output = str(carry) + output
    return output


def main():
    v = ["1", "1"]
    idx = 2
    dummy = ""
    while(len(v[1]) < 1000):
        dummy = v[1]
        v[1] = str_add(v[0],v[1])
        v[0] = dummy
        idx += 1
    print(idx)
    exit()


if __name__ == "__main__":
    main()
