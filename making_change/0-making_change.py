#!/usr/bin/python3
"""determine the fewest number of coins needed to meet a given amount total"""


def makeChange(coins, total):

    if total <= 0:
        return 0

    coins = sorted(coins, reverse=True)
    i = 0

    while total != 0 and coins:
		while coins[0] <= total:
			total -= coins[0]
			i += 1

		coins.pop(0)

	if total != 0:
		return -1
	else:
		return i