#!/usr/bin/python3
"""
function returns a list of lists of integers representing the Pascal’s triangle
"""


def pascal_triangle(n):
	""""a pascal triangle"""
	if n <= 0:
		return []
	t = [[1]]
	for i in range(1, n):
		x = t[-1]
		y = [1]
		for i in range(1, len(x)):
			y.append(x[i - 1] + x[i])
		y.append(1)
		t.append(y)
	return t