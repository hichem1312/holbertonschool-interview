#!/usr/bin/python3
"""
a method that determines if a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    validation
    """
    i = 0
    while i < len(data):
        size = 0
        j = 1 << 7
        while j & data[i]:
            size += 1
            j >>= 1
        if size == 0:
            pass
        elif size == 1 or size > 4:
            return False
        else:
            for k in range(i + 1, i + size):
                if k >= len(data) or (data[k] >> 6) != 2:
                    return False
            i += size - 1
        i += 1
    return True
