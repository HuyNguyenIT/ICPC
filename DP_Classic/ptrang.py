#https://oj.vnoi.info/problem/ptrang
n, l = map(int , input().split())

page = [0 for i in range(n + 5)]
for i in range(1, n + 1):
    page[i] = int(input())
f = [0 for i in range(n + 5)]
for i in range(1, n + 1):
    s = 0
    f[i] = l
    for j in range(i, 0, -1):
        s += page[j]
        if s > l: break
        f[i] = min(f[i], max(f[j - 1], l - s))
print(f[n])