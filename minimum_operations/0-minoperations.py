#!/usr/bin/python3
"""  a method that calculates the fewest number of operations needed
to result in exactly n H characters in the file. """


def minOperations(n):

    a = 2
    b = 0
    if (n < 2):
        return 0
    test = n
    while (test != 1):
        while (test % a == 0):
            test = test / a
            b += a
        a += 1
    return b
