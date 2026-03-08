import sys
a = [True for p in range(1000000)]
for i in range(2,int(1000000**0.5)):
    if a[i]==True:
        for j in range(i*2, 1000000, i) : 
            if a[j] == True :
                a[j] = False
while(True):
    n = int(sys.stdin.readline())
    if n==0 : 
        break
    for i in range(3,1000000):
        if a[i] == True:
            if a[n-i] == True :
                print(n,'=',i,'+',n-i)
                break
