import java.util.*;

public class Main{
	public static int max(int a, int b) {
		return ((a > b) ? a : b);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int INF = 1000000000;
		
		for (int tc = 0; tc < T; tc++) {
			int k = sc.nextInt(), n = sc.nextInt();
			int[] a = new int[n];
			for (int i=0; i<n; i++) a[i] = sc.nextInt();

			int[][][] dp = new int[n][k+1][2];
			for (int i=0; i<n; i++) {
				for (int j=0; j<=k; j++) {
					for (int stat=0; stat<2; stat++) {
						dp[i][j][stat] = -INF;
					}
				}
			}
			dp[0][0][0] = 0; dp[0][0][1] = -a[0];
			
			int ans = 0;
			for (int i=0; i<n; i++) {
				for (int j=0; j<=k; j++) {
					for (int stat=0; stat<2; stat++) {
						if (dp[i][j][stat] == -INF) continue;
						if (i == n-1) {
							if (stat == 0) ans = max(ans, dp[i][j][stat]);
							continue;
						}
						dp[i+1][j][stat] = max(dp[i+1][j][stat], dp[i][j][stat]);
						if (j < k) {
							if (stat == 0) dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][0] - a[i+1]);
							if (stat == 1) dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][1] + a[i+1]);
						}
					}
				}
			}
			System.out.println(ans);
		}
	}
}