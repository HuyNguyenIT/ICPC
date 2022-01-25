/* dp + segment tree */

#include<bits/stdc++.h>

using namespace std;

int const oo = 1e9 + 7;

int const N = 35000 + 123;

struct{
    int f[N << 2], lazy[N << 2];

    void init(int k, int l, int r, int x){
        f[k] = 0;
        lazy[k] = 0;
        if(l == r) {
            f[k] = x;
        }
        if(l < r){
            int m = (l + r) >> 1;
            init(k << 1, l, m, x);
            init(k << 1 | 1, m + 1, r, x);
            f[k] = min(f[k << 1] , f[k << 1 | 1]);
        }
    }

    void down(int k, int l, int r){
        f[k] += lazy[k];
        if(l < r){
            lazy[k << 1] += lazy[k];
            lazy[k << 1 | 1] += lazy[k];
        }
        lazy[k] = 0;
    }

    void update(int k, int l, int r, int L, int R, int v){
        if(l > r) return;
        down(k, l, r);
        if(l > R || L > r) return;
        if(l >= L && r <= R){
            f[k] += v;
            if(l < r){
                lazy[k << 1] += v;
                lazy[k << 1 | 1] += v;
            }
            return;
        }
        int m = (l + r) >> 1;
        update(k << 1, l, m, L, R, v);
        update(k << 1 | 1, m + 1, r, L, R, v);
        f[k] = min(f[k << 1] , f[k << 1 | 1]);
    }


    int get(int k, int l, int r, int L, int R){
        if(l > r) return oo;
        down(k, l, r);
        if(L > r || R < l) return oo;
        if(L <= l && r <= R) return f[k];
        int m = (l + r) >> 1;
        return min(get(k << 1, l, m, L, R) , get(k << 1 | 1, m + 1, r, L, R));	
    }
	
	
} ST[106];

void TestCase(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 5);
    for(int i = 1; i <= n; i++) cin >> v[i];
    vector<vector<int>> dp(k + 5, vector<int>(n + 5, INT_MAX));
    for(int i = 0; i <= k + 5; i++){
        ST[i].init(1, 1, n, oo);
    }
    ST[1].init(1, 1, n, 0);
    map<int, int> prevPos;
    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(prevPos[v[i]] != 0){
            
            ST[1].update(1, 1, n, i, i, answer + i - prevPos[v[i]]);
            answer += i - prevPos[v[i]];
        } else {
            ST[1].update(1, 1, n, i, i, answer);
        }
        prevPos[v[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        dp[1][i] = ST[1].get(1, 1, n, i, i);
    }
    for(int i = 2; i <= k; i++){
        map<int, int> prev;
        for(int j = 1; j <= n; j++){
            if(prev[v[j]] != 0) ST[i - 1].update(1, 1, n, 1 ,prev[v[j]] - 1, j - prev[v[j]]);
            dp[i][j] = ST[i - 1].get(1, 1, n, 1, j - 1);
            prev[v[j]] = j;
        }
        for(int j = i; j <= n; j++){
            ST[i].update(1, 1, n, j, j, dp[i][j] - oo);
        }
    }
    
    cout << dp[k][n] << '\n';
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(); cout.tie();
    
    int tt = 1;
    while(tt--){
        TestCase();
    }
}