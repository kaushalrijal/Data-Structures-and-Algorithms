def insertion_sort(arr):
    n = len(arr)
    for i in range(n):
        j = i-1
        temp = arr[i]

        while j>=0 and temp < arr[j]:
            arr[j+1] = arr[j]
            j-=1
        
        arr[j+1] = temp

        

arr = [12, 17, 2, -1, 0, 1, 15, 100, 8, 19]
print(arr)
insertion_sort(arr)
print(arr)