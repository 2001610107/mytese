def merge_sort(lst, tmp, left, right):
    if left >= right:
        return 0
    mid = (left + right) // 2
    res = merge_sort(lst, tmp, left, mid) + merge_sort(lst, tmp, mid + 1, right)
    i, j, pos = left, mid + 1, left
    while i <= mid and j <= right:
        if lst[i] <= lst[j]:
            tmp[pos] = lst[i]
            i += 1
            res += (j - (mid + 1))
        else:
            tmp[pos] = lst[j]
            j += 1
        pos += 1
    while i <= mid:
        tmp[pos] = lst[i]
        res += (j - (mid + 1))
        pos += 1
        i += 1
    while j <= right:
        tmp[pos] = lst[j]
        j += 1
    lst[left:right + 1] = tmp[left:right + 1]
    return res


def solution(lst):
    n = len(lst)
    tmp = [0] * n
    return merge_sort(lst, tmp, 0, n - 1)


if __name__ == '__main__':
    n = int(input())
    while n > 0:
        lst = []
        for i in range(n):
            m = int(input())
            lst.append(m)
        print(solution(lst))
        n = int(input())

