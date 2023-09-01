#!/usr/bin/python3
"""rotate a given n x n 2D matrix"""

def rotate_2d_matrix(matrix):

    N = len(matrix)
    x = N
    rows = len(matrix)
    cols = len(matrix[0]) if rows > 0 else 0
    matrix_2 = []
    for p in range(rows):
        matrix_2_row = []
        for k in range(cols):
            matrix_2_row.append(matrix[p][k])
        matrix_2.append(matrix_2_row)
    for i in range(0, N):
        x = x - 1
        for j in range(0, N):
            matrix[j][x] = matrix_2[i][j]