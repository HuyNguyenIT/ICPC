INF = 10**9
T = int(input())

for _ in range(T):
	k = int(input())
	n = int(input())
	a = list(map(int, input().split()))

	ans = 0
	dp = [[[-INF for stat in range(2)] for j in range(k+1)] for i in range(n)]
	dp[0][0][0], dp[0][0][1] = 0, -a[0]

	for i in range(n):
		for j in range(k+1):
			for stat in range(2):
				if dp[i][j][stat] != -INF:
					if i == n-1:
						if stat == 0:
							ans = max(ans, dp[i][j][stat])
					else:
						dp[i+1][j][stat] = max(dp[i+1][j][stat], dp[i][j][stat])
						if j < k:
							if stat == 0:
								dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][0] - a[i+1])
							if stat == 1:
								dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][1] + a[i+1])
	
	print(ans)