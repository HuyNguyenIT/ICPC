#https://oj.vnoi.info/problem/qbsquare
n, m = map(int , input().split())
matrix = [[0 for i in range(m + 10)] for j in range(n + 10)]
for i in range(1, n + 1):
    v = list(map(int, input().split()))
    for j in range(1, m + 1):
        matrix[i][j] = v[j - 1]
res = 1
for color in range(0, 2):
    f = [[0 for i in range(m + 10)] for i in range(n + 10)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if matrix[i][j] != color:
                f[i][j] = 0
            else :
                f[i][j] = min( f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            res = max(res, f[i][j])

print(res)