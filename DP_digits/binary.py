#https://oj.vnoi.info/problem/binary
import copy
def ndlist(*args, init=0):
    dp = init
    for x in reversed(args):
        dp = [copy.deepcopy(dp) for _ in range(x)]
    return dp
t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    f = ndlist(33, 2, 2, 33)
    a = []
    if n == 0:
        a.append(0)
    n = int(n)
    while n:
        a.append(1) if(n&1) else a.append(0)
        n = n // 2
    b = [0 for i in range(len(a) + 5)]
    for i in range(1, len(a) + 1):
        b[i] = a[len(a) - i]

    f[0][0][0][0] = 1
    for i in range(0, len(a)):
        for lower in range(0, 2):
            for positive in range(0, 2):
                for k in range(0, i + 1):
                    for next in range(0, 2):
                        cur = f[i][lower][positive][k]
                        if lower == 0 and next > b[i + 1]: continue
                        if cur == 0: continue
                        newLower = lower
                        if lower == 0 and next == b[i + 1]: newLower = 0
                        if lower == 0 and next < b[i + 1]: newLower = 1

                        newK = k
                        if next == 0 and positive: newK += 1
                        newPositive = positive
                        if next == 1 : newPositive = 1;
                        f[i + 1][newLower][newPositive][newK] += cur

    answer = 0
    for lower in range(0, 2):
        answer += f[len(a)][lower][1][m]
    if m > len(a):
        print(0)
        continue
    if m == 1 : answer += 1
    print(answer)
