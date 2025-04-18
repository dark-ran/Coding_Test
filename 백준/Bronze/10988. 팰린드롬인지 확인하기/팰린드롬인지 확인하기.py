a=input()
b=True
for i in range(len(a)):
    if(a[i]!=a[-i-1]):
        b=False
        break
if(b):
    print(1)
else:
    print(0)