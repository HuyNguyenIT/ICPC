#https://oj.vnoi.info/problem/ctnbulls
mod = 2111992
n, k = map(int, input().split())
f = [0 for i in range(n + 5)]
s = [0 for i in range(n + 5)]

for i in range(1, n + 1):
    j = i - (k + 1)
    j = max(j, 0)
    f[i] = (1 + s[j]) % mod
    s[i] = (s[i - 1] % mod + f[i] % mod) % mod
print((s[n] + 1) % mod)
