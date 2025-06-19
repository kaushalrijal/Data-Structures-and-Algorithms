def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        least = arr[i]
        pos = i

        for j in range(i+1, n):
            if least > arr[j]:
                least = arr[j]
                pos = j;

        if not pos == i:
            arr[i], arr[pos] = arr[pos], arr[i]
        

arr = [12, 17, 2, -1, 0, 1, 15, 100, 8, 19]
print(arr)
selection_sort(arr)
print(arr)