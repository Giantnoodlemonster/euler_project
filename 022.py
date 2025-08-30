#!/usr/bin/env python3
# Using names.txt, a 46K text file containing  over five-thousand names, begin by sorting it into alphabetical order.
# Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list
# to obtain a name score.
#
# For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the
# 938th name in the list. So, COLIN would obtain a score of 938 * 53 = 49714.
#
# What is the total of all the name scores in the file?

def parse(filename):
    with open(filename, "r") as file:
        data = file.read()
    data = data.replace("\"","").split(",")
    return data


def name_compare(s1, s2):
    l1 = len(s1)
    l2 = len(s2)
    l = min(l1,l2)

    s1_first = True
    for i in range(l):
        if s1[i] == s2[i]:
            pass
        else:
            s1_first = True if s1[i] < s2[i] else False
            break

    if s1_first is True and s1[:l] == s2[:l] and l2 < l1:
        s1_first = False

    return s1_first


def name_value(s):
    x = 0
    A = ord("A")
    for c in s:
        x += ord(c) - A + 1
    return x


def sort(data):
    is_sorted = False
    n_passes = 0
    while(is_sorted is False):
        is_sorted = True
        n_passes += 1
        for i in range(len(data)-n_passes):
            if name_compare(data[i], data[i+1]):
                pass
            else:
                is_sorted = False
                s = data[i]
                data[i] = data[i+1]
                data[i+1] = s


def main():
    data = parse("022_names.txt")
    sort(data)

    x = 0
    for i, s in enumerate(data):
        x += (i+1) * name_value(s)
    print(x)

if __name__ == "__main__":
    main()
