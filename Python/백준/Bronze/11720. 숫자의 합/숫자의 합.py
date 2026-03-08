import sys
n=int(sys.stdin.readline())
arr=sys.stdin.readline()
sum=int(0)
for i in range(n):
    sum+=int(arr[i])
print(sum)