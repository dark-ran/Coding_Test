import sys
n=int(sys.stdin.readline())
arr=list(map(int,sys.stdin.readline().split()))
print((sum(arr)/(n*max(arr)))*100)