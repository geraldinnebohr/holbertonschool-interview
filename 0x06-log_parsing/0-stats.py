#!/usr/bin/python3
"""script that reads stdin line by line and computes metrics"""

import fileinput
import signal
import sys


def signal_handling(signum, frame):
    """handle ctrl + c keyboard interruption signal"""
    print('File size: {}'.format(sum_file_size))
    for key, value in status_code.items():
        if value != 0:
            print('{}: {}'.format(key, value))

sum_file_size = 0
status_code = {200: 0,
               301: 0,
               400: 0,
               401: 0,
               403: 0,
               404: 0,
               405: 0,
               500: 0}

i = 0
signal.signal(signal.SIGINT, signal_handling)
for line in fileinput.input():
    args = line.split()
    status_line = int(args[-2])
    file_size = args[-1]
    status_code[status_line] += 1
    sum_file_size += int(file_size)
    i += 1
    if i % 10 == 0:
        terminate = False
        print('File size: {}'.format(sum_file_size))
        for key, value in status_code.items():
            if value != 0:
                print('{}: {}'.format(key, value))
