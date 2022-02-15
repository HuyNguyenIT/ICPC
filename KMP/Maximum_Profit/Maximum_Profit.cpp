#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int k, n;
vector<int> a;

void Input() {
	cin >> k >> n;
	a.clear(); a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	int ans = 0;
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, INT_MIN)));
	dp[0][0][0] = 0; dp[0][0][1] = -a[0];
	for (int i=0; i<n; i++) {
		for (int j=0; j<=k; j++) {
			for (int stat=0; stat<2; stat++) {
				if (dp[i][j][stat] == INT_MIN) continue;
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
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}