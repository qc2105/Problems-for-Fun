from newton import square_root_through_newton_method
import math


def test_newton():
    assert(square_root_through_newton_method(9, 0.0001) == 3)
    assert(abs(square_root_through_newton_method(
        555, 0.0001) - math.sqrt(555)) < 0.0001)
