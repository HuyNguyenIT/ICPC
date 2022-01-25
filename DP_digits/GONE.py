#https://www.spoj.com/problems/GONE/
import copy
import math

def ndlist(*args, init=0):
    dp = init
    for x in reversed(args):
        dp = [copy.deepcopy(dp) for _ in range(x)]
    return dp

def is_prime(x):
    if x < 2 : return False
    if x == 2: return True
    for i in range(2, (int)(math.sqrt(x)) + 1):
        if x % i == 0: return False
    return True

def getDigits(n):
    f = ndlist(10, 2,100)
    f[0][0][0] = 1
    rbits = [0 for i in range(10)]
    tmp = n
    idx = 1
    while tmp > 0 :
        rbits[idx] = tmp % 10
        tmp = tmp // 10
        idx += 1
    idx -= 1
    sz = idx
    bits = [0 for i in range(10)]
    for i in range(1, idx + 1):
        bits[i] = rbits[sz - i + 1]
    for i in range(0, idx):
        for lower in range(0, 2):
            for sum in range(0, 100):
                for next in range(0, 10):
                    cur = f[i][lower][sum]
                    if cur == 0: continue
                    lower2 = lower
                    if lower == 0 and next > bits[i + 1]:
                        continue
                    if lower == 0 and next == bits[i + 1] : lower2 = 0
                    elif lower == 0 and next < bits[i + 1] : lower2 = 1
                    f[i + 1][lower2][sum + next] += cur
    res = 0
    for i in range(0, 100):
        if is_prime(i): res += f[idx][1][i] + f[idx][0][i]
    return res
ntest = int(input())
for i in range(ntest):
    L, R = map(int, input().split())

    print(getDigits(R) - getDigits(L - 1))
