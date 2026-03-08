import sys

n = list(map(str, sys.stdin.readline().strip()))
a = []
res = 0

for i in range(len(n)):
    if n[i] == "(":
        a.append("(")
    elif n[i - 1] == ")":
        a.pop()
        res += 1
    else:
        a.pop()
        res += len(a)
print(res)
