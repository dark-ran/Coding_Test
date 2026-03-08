import sys
n, k = map(int, sys.stdin.readline().split())
a = [i for i in range(1, n + 1)]
b = []
c = k - 1

for i in range(n):
    if len(a) > c:
        b.append(a.pop(c))
        c += k - 1
    elif len(a) <= c:
        c = c % len(a)
        b.append(a.pop(c))
        c += k -1 
print("<",end="")
for i in range(len(b)-1):
    print(b[i],', ',end="",sep="")
print(b[len(b)-1],end="")
print('>')
