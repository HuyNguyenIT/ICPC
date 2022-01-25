#https://oj.vnoi.info/problem/nkrez
class item:
    def __init__(self, first, second):
        self.first = first
        self.second = second

n = int(input())

v = [[] for i in range(30005)]
a = []
for i in range(n):
    first, second = map(int, input().split())
    a.append(item(first, second))
    v[second].append(i)
f = [0 for i in range(0, 30005)]
for i in range(1, 30001):
    f[i] = f[i - 1]
    for j in range(0, len(v[i])):
        f[i] = max(f[i], f[a[v[i][j]].first] + a[v[i][j]].second - a[v[i][j]].first)
print(f[30000])



