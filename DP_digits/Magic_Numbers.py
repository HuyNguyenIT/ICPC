#https://codeforces.com/contest/628/problem/D
import copy
def ndlist(*args, init=0):
    dp = init
    for x in reversed(args):
        dp = [copy.deepcopy(dp) for _ in range(x)]
    return dp
mod = 10**9 + 7
def getDigits(N, d , m) :
    idx = 1
    bit = [0 for i in range(0, len(N) + 5)]
    for i in range(1, len(N) + 1):
        bit[i] = int(N[i - 1])
    f = ndlist(10, 2, 2, m + 1, 2)
    f[0][0][0][0][0] = 1
    idx = len(N)

    for i in range(0, idx):
        for lower in range(0, 2):
            for positive in range(0, 2):
                for remaind in range(0, m ):
                    for exits in range(0, 2):
                        for next in range(0, 10):
                            if lower == 0 and next > bit[i + 1]: continue
                            #
                            # if (idx - i) % 2 == 0 and next == d: continue
                            # if positive == 1 and (idx - i) % 2 == 1 and next != d: continue
                            # if positive == 0 and (idx - i) % 2 == 1 and next != 0 and next != d: continue
                            if len(N) % 2 == 0:
                                if (idx - i) % 2 == 0 and next == d: continue
                                if positive == 1 and (idx - i) % 2 == 1 and next != d: continue
                                if positive == 0 and (idx - i) % 2 == 1 and next != 0 and next != d: continue
                            if len(N) % 2 == 1:
                                if (idx - i) % 2 == 1 and next == d: continue
                                if positive == 1 and (idx - i) % 2 == 0 and next != d: continue
                                if positive == 0 and (idx - i) % 2 == 0 and next != 0 and next != d: continue
                            lower2 = lower
                            exits2 = exits
                            if next == d: exits2 = 1
                            if lower == 0 and next == bit[i + 1] : lower2 = 0
                            elif lower == 0 and next < bit[i + 1] : lower2 = 1
                            remaind2 = remaind * 10 + next
                            remaind2 %= m
                            positive2 = positive
                            if next > 0 : positive2 = 1
                            cur = f[i][lower][positive][remaind][exits] % mod
                            f[i + 1][lower2][positive2][remaind2][exits2] = f[i + 1][lower2][positive2][remaind2][exits2] % mod + cur % mod


    return (f[idx][0][1][0][1] + f[idx][1][1][0][1]) % mod


m, d = map(int, input().split())
L = input()
R = input()
ll = int(L)
ll -= 1
if int(L) < 10 and int(R) < 10:
    print(int(R)//m - int(L)//m)
else :print(getDigits(R, d, m) - getDigits(L, d, m))