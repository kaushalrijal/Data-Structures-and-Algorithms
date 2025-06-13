def GCD(a, b):
    if b==0:
        return a
    else:
        return GCD(b, a%b)

a, b = int(input("Enter two numbers: ")), int(input())
print(GCD(a, b))