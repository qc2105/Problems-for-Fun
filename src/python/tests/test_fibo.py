from fibo import fibo
from fibo import fibo_the_loop_way


def test_fibo():
    assert fibo(0) == 1
    assert fibo(2) == 2
    assert fibo(3) == 3


def test_fibo_the_loop_way():
    assert fibo_the_loop_way(0) == 1
    assert fibo_the_loop_way(2) == 2
    assert fibo_the_loop_way(3) == 3
