#!/usr/bin/python3
""" 5-island_perimeter.py"""


def island_perimeter(grid):
    """ function of island perimeter """

    p, i, w, h = 0, 0, len(grid[0]) - 1, len(grid) - 1

    while i <= h:
        j = 0
        while j <= w:
            if grid[i][j] == 1:
                if j == w or grid[i][j + 1] == 0:
                    p += 1

                if grid[i][j - 1] == 0 or j == 0:
                    p += 1

                if i == h or grid[i + 1][j] == 0:
                    p += 1

                if grid[i - 1][j] == 0 or i == 0:
                    p += 1

            j += 1

        i += 1

    return p
