def partition(arr, l, r):
    x, y = l, r
    pivot = arr[l]

    while x<y:
        while x<=r and arr[x] <= pivot:
            x+=1
        while arr[y] > pivot:
            y-=1
        
        if(x < y):
            arr[x], arr[y] = arr[y], arr[x]

    arr[l], arr[y] = arr[y], arr[l]  
    return y

def quick_sort(arr, l, r):
    if l<r:
        p = partition(arr, l, r);
        quick_sort(arr, l, p-1)
        quick_sort(arr, p+1, r)
        

arr = [12, 17, 2, -1, 0, 1, 15, 100, 8, 19]
print(arr)
quick_sort(arr, 0, 9)
print(arr)