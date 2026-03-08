import sys
from collections import deque

a = int(sys.stdin.readline())
b = deque()
while 1:
    c = int(sys.stdin.readline())
    if c == -1:
        break
    elif c != 0 and len(b) < a:
        b.append(c)
    elif c == 0:
        b.popleft()
if len(b) !=0:
    print(*b)
else: 
    print("empty")
