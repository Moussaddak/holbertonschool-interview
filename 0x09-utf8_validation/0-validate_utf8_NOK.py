#!/usr/bin/python3
"""
UTF-8 Validation of data set
"""

import re


def validUTF8(data):

    nbytes = 0
    for num in data:
        binary = bin(num)
        binaryList = re.split("0b", binary)
        bc = binaryList[1].rjust(8, '0')
        if nbytes != 0:
            nbytes -= 1
            if not bc.startswith('10'):
                return(False)
        elif bc[0] == '1':
            nbytes = len(bc.split('0')[0]) - 1
    return(True)
