#!/usr/bin/python3
"""Pascal's Triangle"""


def pascal_triangle(n):
    """
        pascal triangle methode
    """
    if n <= 0:
        return []

    ptri = [[1]]

    while n > 1:
        prev = ptri[-1]

        curr = [1] + [
            prev[j] + prev[j + 1]
            for j in range(len(prev) - 1)
        ] + [1]

        ptri += [curr]
        n -= 1

    return ptri
