#!/usr/bin/python3
"""
    0. Rain task
"""
from typing import List


def rain(walls: List[int]) -> int:
    """
        calculate retained water after the rain
    :param walls:
    :return: total amount of retained rainwater
    """

    if walls is None \
            or not len(walls):
        return 0

    Ln = len(walls)
    water = 0
    for x in range(1, Ln - 1):

        Lt = walls[x]
        for y in range(x):
            Lt = max(Lt, walls[y])
        Rt = walls[x]

        for y in range(x + 1, len(walls)):
            Rt = max(Rt, walls[y])

        water += min(Lt, Rt) - walls[x]

    return water
