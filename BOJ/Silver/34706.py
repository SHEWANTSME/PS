# dongshop - S2 - 2025.11.14
# adhoc인데 몇개 그려보면 감이 옴 -> 중간에 1자로 두면 됨
import sys
input = lambda: sys.stdin.readline().rstrip()
tc=int(input())
while(tc>0):
    x=int(input())
    if x==1: print("1 1")
    if x==2 or x==3 or x==4:
        for i in range(1,x+1):
            print(2, i)
    if x>4:
        if x%2: tmp=1+x//2
        else: tmp=x//2
        for i in range(1,x+1):
            print(tmp, i)
    tc-=1