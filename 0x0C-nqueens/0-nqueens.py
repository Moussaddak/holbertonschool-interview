#!/usr/bin/python3
"""N queens puzzle"""
import sys
from typing import List


def isOK(board: List[List[int]], row: int, col: int, N: int) -> bool:
    """
    test
    """
    for i in range(col):
        if board[row][i] + board[row][i + 1] == 1:
            return False

    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True


def nQueen_R(board: List[List[int]], col: int, N: int) -> bool:
    """
    queen sol°
    """

    if (col >= N):
        printBoard(board)

    for row in range(N):
        if isOK(board, row, col, N):
            board[row][col] = 1
            if nQueen_R(board, col+1, N):
                return True
            board[row][col] = 0

    return False


def printBoard(board: List[List[int]]) -> None:
    """
    print
    """
    line = []
    for x in board:
        for c in x:
            if c == 1:
                line.append([board.index(x), x.index(c)])
    print(line)



N = sys.argv
if len(N) != 2:
    print("Usage: nqueens N")
    sys.exit(1)
if N[1].isnumeric():
    N = int(N[1])
else:
    print("N must be a number")
    sys.exit(1)
if N < 4:
    print("N must be at least 4")
    sys.exit(1)
board = [[0 for i in range(N)] for j in range(N)]
nQueen_R(board, 0, N)
