def sequential_search(lst, key):
    length = len(lst)
    print(f"length:{length} lst:{lst}")
    for i in range(length):
        if lst[i] == key:
            return i
    return False


def binary_search(lst, key):
    length = len(lst)
    left = 0
    right = length - 1
    print(f"length:{length} lst:{lst}")
    while left <= right:
        mid = (right + left) // 2
        if lst[mid] > key:
            right = mid - 1
        elif lst[mid] < key:
            left = mid + 1
        else:
            return mid
    return False


if __name__ == '__main__':
    alst = [1, 5, 7, 8, 22, 54, 99, 123, 200, 222, 444]
    print(f"The key is:{54}  The location of sequential search is:{sequential_search(alst, 54)}")
    print(f"The key is:{99}  The location of binary search is:{binary_search(alst, 99)}")

