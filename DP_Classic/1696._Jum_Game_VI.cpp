#include<bits/stdc++.h>

using namespace std;

int const N = 1e5 + 123;

struct{
	long long f[N << 2], lazy[N << 2];

	void init(long long k, long long l, long long r){
		if(l == r) {
			f[k] = -INT_MAX;
		}
		if(l < r){

			long long m = (l + r) >> 1;
			init(k << 1, l, m);
			init(k << 1 | 1, m + 1, r);
			f[k] = max(f[k << 1] , f[k << 1 | 1]);
		}
	}

	void update(long long k, long long l, long long r, long long L, long long R, long long v){
		if(l > r) return;
		if(l > R || L > r) return;
		if(l >= L && r <= R){
			f[k] = v;
			return;
		}
		long long m = (l + r) >> 1;
		update(k << 1, l, m, L, R, v);
		update(k << 1 | 1, m + 1, r, L, R, v);
		f[k] = max(f[k << 1], f[k << 1 | 1]);
	}

	long long get(long long k, long long l, long long r, long long L, long long R){
		if(l > r) return -INT_MAX;
		if(L > r || R < l) return -INT_MAX;
		if(L <= l && r <= R) return f[k];
		long long m = (l + r) >> 1;
		return max(get(k << 1, l, m, L, R) , get(k << 1 | 1, m + 1, r, L, R));	
	}

} ST;

class Solution {
public:
    long long maxResult(vector<long long>& v, long long k) {
        long long n = v.size();
        vector<long long> dp(n + 5, -(long long )(1e17));
        dp[1] = v[0];
        ST.init(1, 1, n);
        ST.update(1, 1, n, 1,1, dp[1]);
        for(long long i = 2; i <= n; i++){
            long long p = max(i - k , (long long)(1));
            dp[i] = ST.get(1, 1, n, p, i - 1) + v[i - 1];
            ST.update(1, 1, n,i, i, dp[i]); 
        }
        return dp[n];
    }
};

void solve(){
    long long n; cin >> n;
    vector<long long> v(n);
    for(auto&x : v) cin >> x;
    long long k; cin >> k;
    cout << Solution().maxResult(v, k) << '\n';

}

int32_t main(){
    ios_base :: sync_with_stdio(false); cout.tie(); cin.tie();
    freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
}