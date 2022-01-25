#https://lightoj.com/problem/investigation
import copy
def ndlist(*args, init=0):
    dp = init
    for x in reversed(args):
        dp = [copy.deepcopy(dp) for _ in range(x)]
    return dp

def getDigits(N, K) :
    rbit = [0 for i in range(11)]
    idx = 1
    while N > 0 :
        rbit[idx] = N % 10
        N //= 10
        idx += 1
    bit = [0 for i in range(11)]
    for i in range(1, idx):
        bit[i] = rbit[idx - i]
    f = ndlist(11, 2, 85, 85)
    # f(i, lower, remaind_of_n % K, sum_of_digits_n % K)
    f[0][0][0][0] = 1
    idx -= 1
    for i in range(0, idx):
        for lower in range(0, 2):
            for remN in range(0, K):
                for remOfSumDigitN in range(0, K):
                    for next in range(0, 10):
                        if lower == 0 and next > bit[i + 1]: continue
                        remN2 = remN * 10 + next
                        remOfSumDigitN2 = remOfSumDigitN + next
                        lower2 = lower
                        if lower == 0 and next == bit[i + 1]: lower2 = 0
                        if lower == 0 and next < bit[i + 1] : lower2 = 1
                        f[i + 1][lower2][remN2 % K][remOfSumDigitN2 % K] += f[i][lower][remN][remOfSumDigitN]
    return f[idx][0][0][0] + f[idx][1][0][0]


ntest = int(input())
for i in range(1, ntest + 1):
    L, R, K = map(int, input().split())
    ii = str(i)
    if K > 85: print("Case" , ii + ':', 0)

    else: print("Case" , ii + ":", getDigits(R, K) - getDigits(L - 1, K))



