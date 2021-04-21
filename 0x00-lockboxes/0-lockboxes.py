#!/usr/bin/python3
def canUnlockAll(boxes):
    """
    Determines if all the boxes can be opened
    return: True or False
    """
    keys = [0]
    for index, box in enumerate(boxes):
        for key in box:
            if index in box and index != len(boxes) - 1:
                return False
            elif key not in keys:
                keys.append(key)
    keys.sort()
    if keys == list(range(len(boxes))):
        return True
    else:
        return False
