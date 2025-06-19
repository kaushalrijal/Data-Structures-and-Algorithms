def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

arr = [12, 17, 2, -1, 0, 1, 15, 100, 8, 19]
print(arr)
bubble_sort(arr)
print(arr)