#!/usr/bin/python3
"""a script that reads stdin line by line and computes metrics"""
import sys

if __name__ == "__main__":
    st_file = {"200": 0,
               "301": 0,
               "400": 0,
               "401": 0,
               "403": 0,
               "404": 0,
               "405": 0,
               "500": 0}
    s = 0
    v = 1

    def print_s():
        """printing the stats"""
        print("File size: {}".format(s))
        for j in sorted(st_file.keys()):
            if st_file[j]:
                print("{}: {}".format(j, st_file[j]))
    try:
        for i in sys.stdin:
            line_s = i.split()
            status_code = line_s[-2]
            if status_code in st_file.keys():
                st_file[status_code] += 1
            s = s + int(line_s[-1])
            if v % 10 == 0:
                print_s()
            v += 1
    except KeyboardInterrupt:
        print_s()
        raise
    print_s()
