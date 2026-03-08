a=input()
for _ in range(len(a)//10):
    print(a[10*_:10*_+10])
if(len(a)%10!=0):
    print(a[10*(len(a)//10)::])