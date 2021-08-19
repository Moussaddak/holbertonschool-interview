#!/usr/bin/python3
"""
0. Rain
"""


def func(array, start):
    """
    :param array:
    :param start:
    :return:
    """
    for i in array[start + 1:]:
        if i != 0:
            end = array.index(i)
            count = array[start:end + 1].count(0)
            return ([end, array[end]], count) if array[start] > array[end] else ([end, array[start]], count)
    else:
        return [start, 0], 0


def rain(walls):
    water = 0
    for i in walls:
        if walls.index(i) and walls.index(i) < len(walls):
            # print(i, end=" ")
            idx_value, zeros = func(walls, walls.index(i))
            print(f"\"0\" :: {zeros}", "***", idx_value[1] * zeros, f"end index {idx_value[0]}")
            water += idx_value[1] * zeros
            i = walls[idx_value[0]]
    return water


walls = [0, 1, 0, 2, 0, 3, 0, 4, 0, 0, 1]
fffff = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(rain(walls))
walls = [2, 0, 0, 4, 0, 0, 1, 0]
# walls = [2, 0, 0, 4, 0, 0, 1, 0]
# print(rain(walls))
