#include <bits/stdc++.h>

using namespace std;

#define int long long

int const N = 1e6;

void solve() {
    int n; cin >> n;
    vector<int> v(n + 5), pos(n + 5);

    for(int i = 0; i < n; i++) cin >> v[i], pos[v[i]] = i + 1;

    int answer = 1;

    for(int i = 2; i <= n; i++){
        if(pos[i] < pos[i - 1]) answer += 1;
    }
    cout << answer << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    
    while (t--) {
        solve();
    }
    
    return 0;
}