n=int(input())
while True:
    for i in range(2,n+1):
        if(n%i==0):
            n=int(n/i)
            print(i)
            break
    if(n==1):
        break