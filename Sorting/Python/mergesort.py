import math

temp = [0 for i in range(10)]

def merge(arr, l, m, r):
    i, j, k = l, m, l
    while i < m and j <= r:
        if arr[i] < arr[j]:
            temp[k] = arr[i]
            i += 1
        else:
            temp[k] = arr[j]
            j += 1
        k += 1

    while i < m:
        temp[k] = arr[i]
        i += 1
        k += 1
    while j <= r:
        temp[k] = arr[j]
        j += 1
        k += 1

    for x in range(l, r+1):
        arr[x] = temp[x]

def merge_sort(arr, l, r):
    if l<r:
        mid = math.floor((r+l)/2)
        merge_sort(arr, l, mid)
        merge_sort(arr, mid+1, r)
        merge(arr, l, mid+1, r)
        

arr = [12, 17, 2, -1, 0, 1, 15, 100, 8, 19]
print(arr)
merge_sort(arr, 0, 9)
print(arr)