#!/usr/bin/python3
""" a method that determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    for i in range(1, len(boxes) - 1):
        check = 0
        x = 0
        for j in boxes:
            if (i in j) and i != x:
                check = 1
            x += 1
        if check == 0:
            return(False)
    return(True)