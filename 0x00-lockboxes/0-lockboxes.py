#!/usr/bin/python3
def canUnlockAll(boxes):
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

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))

