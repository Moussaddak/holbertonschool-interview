#!/usr/bin/python3
"""
write script parse log by reading stdin line by line
and computes metrics:
    - After every 10 lines and/or a keyboard interruption (CTRL + C),
      print these statistics from the beginning
"""

import re
import sys


def print_stat(fsize: int, stat: dict):
    print("File size: {}".format(fsize))
    stat_items = stat.items()
    sorted_stat = sorted(stat_items)
    for http_code, num in sorted_stat:
        print("{}: {}".format(http_code, num))


protocol = r'"GET /projects/260 HTTP/1.1"'
regex = "^[\d\w.?]+\s?-\s?\[[0-9-:\s.]+\]\s" + \
    protocol + "\s([\w\d]+)\s([0-9]+)$"
tsize = 0
code = ["200", "301", "400", "401", "403", "404", "405", "500"]
stat = {}
count = 0
try:
    for line in sys.stdin:
        count += 1
        line = line.rstrip()
        r = re.search(regex, line)
        if r is None:
            continue
        status_code, fsize = r.group(1), r.group(2)
        tsize += int(fsize)
        if status_code in code:
            stat[status_code] = stat.get(status_code, 0) + 1
        else:
            continue
        if count == 10:
            count = 0
            print_stat(tsize, stat)
except KeyboardInterrupt:
    print_stat(tsize, stat)
    raise
finally:
    print_stat(tsize, stat)
