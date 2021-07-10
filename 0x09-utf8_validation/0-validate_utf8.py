#!/usr/bin/python3
"""
UTF-8 Validation of data set
"""


def validUTF8(data):
    """
        :type data: List[int]
        :rtype: bool
    """

    count = 0
    for num in data:
        tmp = 1 << 7
        if count == 0:
            while tmp & num:
                count += 1
                tmp >>= 1
            if count > 4:
                return False
        elif num >> 6 != 2:
            return False
        if count:
            count -= 1
    return count == 0
