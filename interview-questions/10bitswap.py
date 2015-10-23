#!/usr/bin/env python
"""
Swap adjacent bits.

Usage: python 10bitswap.py <integer>
"""

import sys

def bit_swap(n):
    """
    Swaps adjacent bits.

    >>> bin(5)
    '0b101'

    >>> bin(bitswap(5))
    '0b1010'
    """
    # Get the even numbered bits by masking with 0101010101010101
    # Bit 0 is on the right
    even_bits = n & 0x55555555

    # Get the odd numbered bits by masking with 1010101010101010
    odd_bits = n & 0xaaaaaaaa

    # Shift the even bits left by 1 and the odd bits right by 1
    # The leftmost bit of even_bits and the rightmost bit of odd_bits
    # is a zero so we don't need to worry about overflow.
    # Or these two values together to get the bit-swapped number.
    return (even_bits << 1) | (odd_bits >> 1)

if __name__ == '__main__':
    n = int(sys.argv[1])
    print 'Original: {0:032b}, Swapped: {1:032b}'.format(n, bit_swap(n))
