def block_search(lst, block_count, key):
    length = len(lst)
    block_length = length // block_count
    if block_count * block_length != length:
        block_length += 1
    print(f"block_length:{block_length}")
    for block_i in range(block_length):
        block_lst = []
        for i in range(block_count):
            if block_i * block_count + i >= length:
                break
            block_lst.append(lst[block_i * block_count + i])
        result = binary_search(block_lst, key)
        if result:
            return block_i * block_count + result
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
    print(f"The key is:{54}  The location of  block_search is:{block_search(alst, 4, 54)}")
