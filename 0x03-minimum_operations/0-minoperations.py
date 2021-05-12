#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations in this file:
Copy All and Paste. Given a number n, write a method that calculates
the fewest number of operations needed to result in exactly n H characters
in the file.
"""


def minOperations(n):
    """
    @nH  :: current number of H chars
    @cp  :: how many copy done
    @pt  :: how many pt done
    @ctp :: how many chars to paste
    """
    nH, cp, pt, ctp = 1, 0, 0, 0

    while (nH < n):
        # check for copy ops
        if (n % nH == 0 and nH * 2 <= n):
            cp += 1
            ctp = nH
        # check for paste ops
        if nH + ctp <= n:
            pt += 1
            nH += ctp
    if nH == n:
        return (cp + pt)
    return 0
