#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
 
void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> v(n + 5, vector<int>(m + 5));

    for(int i = 0; i < n; i++)for(int j = 0; j < m;j++) cin >> v[i][j];

    vector<int> minROW(n + 5, INT_MAX);

    vector<int> minCol(m + 5, INT_MAX);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            minROW[i] = min(minROW[i], v[i][j]);
        }
    }

    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            minCol[j] = min(minCol[j], v[i][j]);
        }
    }

    int answer = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == minROW[i] && v[i][j] <= minCol[j]){
                answer += 1;
            }
        }
    }

    cout << answer << '\n';

}
 
int main() {
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