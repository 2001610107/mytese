def bubble_sort(lst):
    n = len(lst)
    if n <= 1:
        return lst
    for i in range(0, n):
        for j in range(0, n - i - 1):
            if lst[j] > lst[j + 1]:
                (lst[j], lst[j + 1]) = (lst[j + 1], lst[j])
    return lst


def insert_sort(lst):
    n = len(lst)
    if n <= 1:
        return lst
    for i in range(1, n):
        j = i
        target = lst[i]
        while j > 0 and target < lst[j - 1]:
            lst[j] = lst[j - 1]
            j = j - 1
        lst[j] = target
    return lst


def quick_sort(list, left, right):
    if len(list) <= 1 or left > right:
        return
    tmp = list[left]
    i = left
    j = right
    while i < j:
        while i < j and tmp <= list[j]:
            j -= 1
        while i < j and tmp >= list[i]:
            i += 1
        if i < j:
            (list[i], list[j]) = (list[j], list[i])

    (list[left], list[i]) = (list[i], tmp)
    quick_sort(list, left, j - 1)
    quick_sort(list, j + 1, right)


def quick__sort(lst):
    def partition(lst, left, right):
        tmp = left
        while left < right:
            while left < right and lst[tmp] <= lst[right]:
                right -= 1
            while left < right and lst[tmp] >= lst[left]:
                left += 1
            (lst[left], lst[right]) = (lst[right], lst[left])
        (lst[left], lst[tmp]) = (lst[tmp], lst[left])
        return left

    def quicksort(lst, left, right):
        if len(lst) <= 1 or left >= right:
            return
        mid = partition(lst, left, right)
        quicksort(lst, left, mid - 1)
        quicksort(lst, mid + 1, right)

    quicksort(lst, 0, len(lst) - 1)
    return lst


def merge_sort(lst):
    def merge(lst, left, mid, right):
        temp = []
        i = left
        j = mid + 1
        while i <= mid and j <= right:
            if lst[i] <= lst[j]:
                temp.append(lst[i])
                i += 1
            else:
                temp.append(lst[j])
                j += 1
        while i <= mid:
            temp.append(lst[i])
            i += 1
        while j <= right:
            temp.append(lst[j])
            j += 1
        for i in range(left, right + 1):
            lst[i] = temp[i - left]

    def sort(lst, left, right):
        if left >= right:
            return
        mid = (left + right) // 2
        sort(lst, left, mid)
        sort(lst, mid + 1, right)
        merge(lst, left, mid, right)

    if len(lst) <= 1:
        return lst
    sort(lst, 0, len(lst) - 1)
    return lst


if __name__ == "__main__":
    lst = [1, 3, 5, 4, 2, 100, 20]
    lst = lst
    print("lst:", lst)
    lst1 = lst.copy()
    lst2 = lst.copy()
    lst3 = lst.copy()
    lst4 = lst.copy()
    bubble_sort(lst)
    insert_sort(lst1)
    quick_sort(lst2, 0, len(lst2) - 1)
    quick__sort(lst3)
    merge_sort(lst4)
    print("冒泡排序:", lst)
    print("插入排序：", lst1)
    print("快速排序：", lst2)
    print("快速排序1：", lst3)
    print("归并排序:", lst4)
