#include <bits/stdc++.h>

using namespace std;

int const nax = 987654321;

#define int long long

void solve(){
	int n, x; cin >> n >> x;
	
	vector<int> a(n);

	for(auto&p : a) cin >> p;

	int f[n + 5][3][3];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= 3; j++){
			for(int k = 0; k <= 3; k++) f[i][j][k] = -INT_MAX;
		}
	}
	f[0][0][0] = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				if(k < 2) f[i][j][k + 1] = max(f[i][j][k + 1], f[i][j][k]); 
				if(j < 2 )f[i][j + 1][k] = max(f[i][j + 1][k], f[i][j][k]); 
				if(i < n)f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k] + ((j == 1) ? a[i] : 0 ) * ((k == 1) ? x : 1) );
			}
		}
	}

	cout << f[n][2][2] << '\n';
}

int32_t main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(); cout.tie();
	freopen("input.txt", "r", stdin);
	int tt = 1; 
	while(tt--){
		solve();
	}
}