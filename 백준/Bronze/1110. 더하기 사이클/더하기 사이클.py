def func(num):
    b=int(num/10)
    c=int(num%10)
    return int(c*10+(b+c)%10)
a=int(input())
d=a
cnt=0
while True:
    d=func(d)
    cnt+=1
    if(d==a):
        break
print(cnt)