#!/usr/bin/python3
"""calculate how many square units of water will be retained after it rains"""


def rain(walls):
"""function"""
n = len(walls)
if n == 0:
	return 0

l_max = [0] * n
r_max = [0] * n

l_max[0] = walls[0]
for i in range(1, n):
	l_max[i] = max(l_max[i-1], walls[i])

r_max[n-1] = walls[n-1]
for i in range(n-2, -1, -1):
	r_max[i] = max(r_max[i+1], walls[i])

x = 0
for i in range(n):
	x += min(l_max[i], r_max[i]) - walls[i]

return x if x >= 0 else 0