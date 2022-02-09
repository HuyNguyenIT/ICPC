#include <bits/stdc++.h>

using namespace std;

#define int long long
 
void solve() {
    int n; cin >> n; vector<int> v(n);
    for(auto&x : v) cin >> x;
    if(v[0] > 1) {
        cout << -1 << '\n';
        return;
    } else if(v[0] == 0){
        for(int i = 1; i < n; i++){
            if(v[i] != 0){
                cout << -1 << '\n';
                return;
            }
        }
        cout << 1 << '\n';
    } else {
        int answer = -1;
        for(int i = 1; i < n; i++){
            if(v[i] != v[i - 1] * 2){
                if(answer == -1){
                    answer = v[i - 1] * 2 - v[i];
                    if(answer > v[i]) continue;
                    else{
                        cout << -1 << '\n';
                        return;
                    }
                } else {

                    if(v[i - 1] * 2 - v[i] != answer){
                        cout << -1 << '\n';
                        return;
                    }

                    if(answer > v[i]) continue;
                    else{
                        cout << -1 << '\n';
                        return;
                    }
                }
            }
        }
        cout << answer << '\n';
    }

}
 
int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // freopen("input.txt", "r", stdin);

    int t = 1;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}