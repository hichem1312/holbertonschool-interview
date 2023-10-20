#!/usr/bin/python3
"""
a function that returns the perimeter of the island described
"""


def island_perimeter(grid):
   
	if not grid:
		return 0

	x = len(grid)
	y = len(grid[0])
	p = 0

	for i in range(x):
		for j in range(y):
			if grid[i][j] == 1:
				p += 4
				if i > 0 and grid[i-1][j] == 1:
					p -= 2
				if j > 0 and grid[i][j-1] == 1:
					p -= 2
	return p