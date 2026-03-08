_=int(input())
for i in range(_):
    cnt=1
    sum=0
    a=input()
    for b in range(len(a)):
        if(a[b]=='O'):
            sum+=cnt
            cnt+=1
        else:
            cnt=1
    print(sum)