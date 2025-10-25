""" Callbable type """
from typing import Callable
def test_callable_type():
    def my_function(func: Callable[[int, int], int]):
        print(func(1, 2))

    def sum(a: int, b: int) -> int: return a + b

    my_function(lambda x, y: x + y)
    my_function(sum)

if __name__ == '__main__':
    test_callable_type()
   

