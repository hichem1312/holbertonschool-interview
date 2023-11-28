#!/usr/bin/python3
"""Given a set of consecutive integers starting from 1 up to and including n,
they take turns choosing a prime number from the set and removing that number
and its multiples from the set.The player that cannot make a move loses
the game."""


def isWinner(x, nums):
    """function"""
    if not nums or x < 1:
        return None
    max_n = max(nums)
    filters = [True for _ in range(max(max_n + 1, 2))]
    for i in range(2, int(pow(max_n, 0.5)) + 1):
        if not filters[i]:
            continue
        for j in range(i * i, max_n + 1, i):
            filters[j] = False
    filters[0] = filters[1] = False
    c = 0
    for i in range(len(filters)):
        if filters[i]:
            c += 1
        filters[i] = c
    p = 0
    for max_n in nums:
        p += filters[max_n] % 2 == 1
    if p * 2 == len(nums):
        return None
    if p * 2 > len(nums):
        return "Maria"
    return "Ben"