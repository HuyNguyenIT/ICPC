// https://codeforces.com/contest/1625/problem/C
#include<bits/stdc++.h>

using namespace std;

#define int long long

void TestCase(){
    int n, l, m; cin >> n >> l >> m;
    vector<int> d(n), a(n); 
    for(int i = 0; i < n; i++) cin >> d[i];
    for(int i = 0; i < n; i++) cin >> a[i];
    a.push_back(0);
    d.push_back(l);
    vector<vector<int>> f(n + 5, vector<int>(m + 5, INT_MAX));
    f[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = i - 1; k >= 0; k--){
                int dis = j - (i - k - 1);
                if(dis >= 0) {
                    f[i][j] = min(f[i][j], f[k][dis] + (d[i] - d[k]) * a[k]);
                }
            }
        }
    }
    int answer = INT_MAX;
    for(int i =  0; i <= m; i++){
        answer = min(answer, f[n][i]);
    }
    cout << "huy" << endl;

}

int32_t main(){
   ios_base::sync_with_stdio(true);
   cin.tie(); cout.tie();
    freopen("input.txt", "r", stdin);
    int tt = 1;
    while(tt--){
        TestCase();
    }
}
