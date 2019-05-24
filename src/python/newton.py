import os
import math


def f(x, b):
    return x*x - b


def fderivative(x):
    return 2*x


def square_root_through_newton_method(b, threshold):
    assert(b > 0)
    x_0 = 3
    x_1 = x_0 - f(x_0, b)/fderivative(x_0)
    i = 0
    while (abs(x_0 - x_1) >= threshold):
        x_0 = x_1
        x_1 = x_0 - f(x_0, b)/fderivative(x_0)
        i += 1
        print(i)
        if (i > 100000):
            break
    return x_1


if __name__ == '__main__':
    print(square_root_through_newton_method(5555, 0.00001))
