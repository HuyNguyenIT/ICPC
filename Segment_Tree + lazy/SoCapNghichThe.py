from math import ceil, log2
INF = 10 ** 9
def init(ST, k, l, r):
    if l > r :
        return
    if l == r :
        ST[k] = 0
        return
    m = (l + r) >> 1
    init(ST, k * 2, l, m)
    init(ST, k * 2 + 1, m + 1, r)

def query(ST, k, l, r, st, en):
    if l > r:
        return 0
    if st > r or en < l:
        return 0
    if st <= l and en >= r:
        return ST[k]
    m = (l + r) >> 1
    return query(ST, k * 2, l, m, st, en) + query(ST, k * 2 + 1, m + 1, r, st, en)


def update(ST, k, l, r, x):
    if l > r : return
    if(l > x or r < x): return
    if(l == r and l == x) :
        ST[k] += 1
        return
    m = (l + r) >> 1
    update(ST, k * 2, l, m, x)
    update(ST, k * 2 + 1, m + 1, r, x)
    ST[k] = ST[k * 2] + ST[k * 2 + 1]

if __name__ == "__main__" :
   n = int(input())
   v = list(map(int, input().split()))
   b = []
   for x in v:
       b.append(x)
   b.sort()
   dict = {}
   c = []
   cnt = 0
   last = -1
   for i in range(len(b)):
       if i > 0 and b[i] == b[i - 1]:
           dict[b[i]] = dict[b[i - 1]]
           continue
       dict[b[i]] = cnt + 1
       cnt += 1
   for i in v :
       c.append(dict[i])

   h = ceil(log2(n))
   sz = 2 * (2 ** h)
   ST = [0] * sz

   ans = 0
   for x in c:
       y = x
       ans += (query(ST,1, 1, n, y + 1, n))
       update(ST, 1, 1, n, y)
   print(ans)