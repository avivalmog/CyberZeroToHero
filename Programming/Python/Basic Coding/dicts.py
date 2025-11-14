def dicts():
    

    print("------------ Dicts ------------")
    print("###### dict examples ######")
    print("dict1:")
    dict1 = {
        "brand": "Ford",
        "model": "Mustang",
        "year": 1964
    }
    print(dict1)
    print("dict2:")
    dict2 = {
        1: "one",
        2: "two",
    }
    print(dict2)

    print("dict3:")
    dict3 = {
        (1, 2, 3): "list1",
        (4, 5, 6): "list2",
    }

    print(dict3)

    # should throw an error, because lists are not hashable
    try:
        dict4 = {
            [1, 2, 3]: "list1",
            [4, 5, 6]: "list2",
        }
        print(dict4)
    except Exception as e:
        print(e)

    dict = {"A":2}
    print(dict)
    dict["A"] = dict["A"] + 1
    print(dict)

    print("\n###### dict methods ######\n")
    print("dict items are key and value tuples:")
    for item in dict1.items():
        print(type(item))
        print(item)

    print("------------------")
    print("iterating dict keys:")
    for key in dict1.keys():
        print(f"key is: {key}")
        print(f"value is: {dict1[key]}")

    print("------------------")
    print("adding, removing, updating items:")
    print(dict1.keys().__contains__("brand"))
    print(dict1.keys().__contains__("brand2"))
    print(dict1)
    dict1['color'] = 'blue'
    print(dict1)
    dict1.pop('color')
    print(dict1)
    dict1.update({'year': 1970})
    print(dict1)


if __name__ == '__main__':
    dicts()
