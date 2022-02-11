#include <bits/stdc++.h>

using namespace std;

#define int long long
 
void solve() {
    int n, m, k; cin >> n >> m >> k;

    vector<vector<int>> a(n + 5, vector<int>(m + 5));
    vector<vector<int>> b(n + 5, vector<int>(m + 5));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }

    int answer = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int iz = n - i - 1; iz >= 0; iz--){
                for(int jz = m - j - 1; jz >= 0; jz--){
                    for(int u = i; u <= i + iz; u++){
                        for(int v = j; v <= j + jz; v++){
                        }                                         
                    }
                }   
            }
        }
    }

    cout << answer << '\n';

}
 
int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // freopen("input.txt", "r", stdin);

    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}