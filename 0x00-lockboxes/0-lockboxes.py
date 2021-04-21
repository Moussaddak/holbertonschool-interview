#!/usr/bin/python3
"""
Interview Preparation  Algorithms
          Lockboxes
"""


def canUnlockAll(boxes):
    """
    Determines if all the boxes can be opened
    return: True or False
    """
    keys = [0]
    for index, box in enumerate(boxes):
        for key in box:
            if if key != index and key not in keys and key <= len(boxes) - 1:
                keys.append(key)
    keys.sort()
    if keys == list(range(len(boxes))):
        return True
    else:
        return False
