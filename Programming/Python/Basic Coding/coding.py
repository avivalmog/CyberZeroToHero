""" Callbable type """
from typing import Callable
def test_callable_type():
    def my_function(func: Callable[[int, int], int]):
        print(func(1, 2))

    def sum(a: int, b: int) -> int: return a + b

    my_function(lambda x, y: x + y)
    my_function(sum)


def test_data_structures():
    
    def test_data_structures_types() -> None:
        print("---test_data_structures_types---")
        set1 = set()
        set2 = {1,2}

        dict1 = dict()
        dict2 = {}

        list1 = list()
        list2 = []

        tuple1 = tuple()
        tuple2 = ()

        try:
            assert type(set1) == type(set2)
            print("sets:" + str(type(set1)) + str(type(set2)))
            assert type(dict1) == type(dict2)
            print("dicts:" + str(type(dict1)) + str(type(dict2)))
            assert type(list1) == type(list2)
            print("lists:" + str(type(list1)) + str(type(list2)))
            assert type(tuple1) == type(tuple2)
            print("tuples" + str(type(tuple1)) + str(type(tuple2)))
        except AssertionError as error:
            print("wrong data structures types")


    def test_data_structures_operations() -> None:
        print("---test_data_structures_operations---")
        list1 = [1,3,2,3]
        print("list: " + str(list1))
        print("last element: " + str(list1[-1]))
        print("sorted list: " + str(sorted(list1)))
        print("set from list: " + str(set(list1)))

    test_data_structures_types()
    test_data_structures_operations()

   

def test_strings():
    str1 = "bla123%@$"
    print("str:" + str1)
    print("first char:" + str1[0])
    print("last char:" + str1[-1])
    

def test_bytes():

    bytes1 = bytes("abc", "utf-8")
    print(type(bytes1))
    print("bytes:" + str(bytes1))
    print(bytes1)
    
    print("first byte:" + str(bytes1[0]))
    print("last byte:" + str(bytes1[-1]))

    try:
        bytes1[0] = 'd'
    except Exception as e:
        print(e)


    # Creating bytearray
    a = bytearray((12, 8, 25, 2))
    print("Creating Bytearray:")
    print(type(a))
    print(a)

    # accessing elements
    print("\nAccessing Elements:", a[-2])

    # modifying elements 
    a[1] = 4
    print("\nAfter Modifying:")
    print(a)

    # Appending elements
    a.append(255)
    print("\nAfter Adding Elements:")
    print(a)


def test_ranges():
    for i in range(1, 10):
       print(i)

    for i in range(1, 10, 2):
       print(i)

    lowercase_letters = [chr(i) for i in range(ord('a'), ord('z') + 1)]
    print(lowercase_letters)

if __name__ == '__main__':
    print("main function")
    # test_callable_type()
    # test_data_structures()
    # test_strings()
    # test_bytes()
    # test_ranges()
   

