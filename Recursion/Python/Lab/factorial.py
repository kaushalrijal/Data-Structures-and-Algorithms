def tailFact(n, a):
    if(n==0):
        return a
    else:
        return tailFact(n-1, n*a)
    
n = int(input("Enter the term to calculate: "))
print("Result =", tailFact(n, 1))