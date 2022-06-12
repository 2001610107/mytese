def merge_sort(lst, left, right):
    if left >= right:
        return 0
    mid = (left + right) // 2
    res = merge_sort(lst, left, mid) + merge_sort(lst, mid + 1, right)
    i = left
    j = mid + 1
    tmp = []
    while i <= mid and j <= right:
        if lst[i] <= lst[j]:
            tmp.append(lst[i])
            i += 1
        else:
            res += (mid - i + 1)
            tmp.append(lst[j])
            j += 1
    while i <= mid:
        tmp.append(lst[i])
        i += 1
    while j <= right:
        tmp.append(lst[j])
        j += 1
    lst[left:right + 1] = tmp
    return res


if __name__ == '__main__':
    n = int(input())
    while n > 0:
        lst = []
        for i in range(n):
            m = int(input())
            lst.append(m)
        print(merge_sort(lst, 0, n - 1))
        n = int(input())

