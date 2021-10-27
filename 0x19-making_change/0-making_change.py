#!/usr/bin/python3
"""
    0. Change comes from within
"""


def makeChange(coins, total):
    """
    :param coins:
    :param total:
    :return:
    """
    coinsCombo = 0
    if total <= 0:
        return 0
    coins.sort()
    coins.reverse()
    for c in coins:
        coinsCombo += total // c
        total %= c
    return -1 if total != 0 else coinsCombo
