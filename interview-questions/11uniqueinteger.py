#!/usr/bin/env python3
"""
Find the unique integer from an array of integers. Integers that are repeated
will be repeated an even number of times, corresponding to takeoff and landing
ids, as described in the problem. The unique id is the vehicle that tookoff and
never landed.
"""

from functools import reduce
from operator import xor

def unique_integer(ids):
    return reduce(xor, ids, 0)

if __name__ == '__main__':
    import sys

    ids = [1, 2, 3, 2, 3, 1, 5, 4, 7, 4, 6, 5, 6]
    print('ids: {0}, unique integer: {1}'.format(ids, unique_integer(ids)))
