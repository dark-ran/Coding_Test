arr=[]
for i in range(10):
    arr.append(int(input())%42)
arr.sort()
a=arr[0]
cnt=1
for i in range(1,10):
    if(a!=arr[i]):
        cnt+=1
        a=arr[i]
print(cnt)