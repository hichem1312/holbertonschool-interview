#!/usr/bin/python3
'''
a program that solves the N queens problem.
'''
from sys import argv, exit

if __name__ == "__main__":
    if len(argv) != 2:
        print('Usage: nqueens N')
        exit(1)
    try:
        x = int(argv[1])
    except BaseException:
        print('N must be a number')
        exit(1)
    if x < 4:
        print('N must be at least 4')
        exit(1)

    v = []

    def solve_queens(row, x, v):
        if (row == x):
            print(v)
        else:
            for col in range(x):
                place = [row, col]
                if valid_placement(v, place):
                    v.append(place)
                    solve_queens(row + 1, x, v)
                    v.remove(place)

    def valid_placement(v, place):
        for i in v:
            if i[1] == place[1]:
                return False
            if (i[0] + i[1]) == (place[0] + place[1]):
                return False
            if (i[0] - i[1]) == (place[0] - place[1]):
                return False
        return True

    solve_queens(0, x, v)
