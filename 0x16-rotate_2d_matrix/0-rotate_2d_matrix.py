#!/usr/bin/python3
""" 0. Rotate 2D Matrix """


def rotate_2d_matrix(matrix):
    """method rotate_2d_matrix"""
    L = len(matrix)
    tmp = [list(row) for row in zip(*matrix)]
    matrix[:] = [[tmp[i][L - 1 - j] for j in range(L)] for i in range(L)]
