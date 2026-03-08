from collections import deque
import sys

a=int(sys.stdin.readline().strip())
c=deque()
s=deque()
for i in range(a):
    b=sys.stdin.readline().strip().split()
    if b[0] == '1':
        s.append(b[1])
        c.append(b[0])
    elif b[0] == '2':
        s.appendleft(b[1])
        c.append(b[0])
    elif len(s) !=0:
        b=c.pop()
        if b== '1':
            s.pop()
        else:
            s.popleft()
if len(s) !=0:
    print(''.join(s))
else:
    print(0)
