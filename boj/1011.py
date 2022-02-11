from math import *
T = int(input())
for i in range(0, T):
    x, y = input().split()
    x = float(x)
    y = float(y)
    if y - x <= 3:
        print(int(y - x))
    else:
        print(ceil(sqrt(y - x) * 2 - 1))
