#!/usr/bin/python3

import os


# return the nth fibo number
def fibo(n):
    if n == 0:
        return 1
    elif n == 1:
        return 1
    else:
        return fibo(n-2) + fibo(n-1)


def fibo_the_loop_way(n):
    fibo_number = 0
    if n == 0:
        return 1
    elif n == 1:
        return 1
    else:
        a = 1
        b = 1
        for i in range(1, n):
            fibo_number = a + b
            a = b
            b = fibo_number
    return fibo_number


if __name__ == '__main__':
    count = int(os.sys.argv[2])
    if os.sys.argv[1] == "r":
        for n in range(count):
            print(str(n) + ": " + str(fibo(n)))
    elif os.sys.argv[1] == "l":
        for n in range(count):
            print(str(n) + ": " + str(fibo_the_loop_way(n)))
