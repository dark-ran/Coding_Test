n=int(input())
arr=list(map(int,input().split()))
li = [False for _ in range(1002)]
li[1]=True
for i in range(1,1001):
    if(not li[i]):
        for j in range(2*i,1001,+i):
            li[j]=True
cnt=0
for i in range(0,n):
    if(not li[arr[i]]):
        cnt+=1
print(cnt)
