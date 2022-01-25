#https://oj.vnoi.info/problem/icpc21_mb_e
import copy
def ndlist(*args, init=0):
    dp = init
    for x in reversed(args):
        dp = [copy.deepcopy(dp) for _ in range(x)]
    return dp

m =  int(input())
a = [0 for i in range(16)]
index = 1
while m > 0:
    a[index] = m % 10
    m = m // 10
    index += 1
# f[i][remaind][sumx][sumy]
f = [[[[0 for i in range(150)] for i in range(150)]for i in range(4)]for i in range(18)]
f[0][0][0][0] = 1

for i in range(0, index):
    for remaind in range(0, 3):
        for sumx in range(0, 138):
            for sumy in range(0, 138):
                cur = f[i][remaind][sumx][sumy]
                if cur == 0: continue
                # print(cur)
                for x in range(0, 10):
                    for y in range(0, 10):
                        add = x + 2 * y + remaind
                        if add % 10 == a[i + 1]:
                            f[i + 1][add // 10][sumx + x][sumy + y] += cur
answer = 0
list = [2,3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137]

for i in list:
    for j in list:
        answer += f[index][0][i][j]
print(answer)