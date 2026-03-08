li=[]
for _ in range(5):
    a=input()
    res= "FBI" in a
    if(res):
        li.append(int(_+1))
if(len(li)==0):
    print("HE GOT AWAY!")
else:
    print(*li)