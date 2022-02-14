#include<bits/stdc++.h>

using namespace std;

int const N = 1e6 + 123;

void solve(){
    int n; cin >> n; vector<int> v(n);
    for(auto&x : v) cin >> x;
    sort(v.begin(), v.end());
    double answer = 1;
    for(int i = 0; i < n; i++){
        answer = min((double)v[i]/(i + 1), answer);
        if((double)v[i]/(i + 1) > 1){
            cout << -1 << '\n';
            return;
        }
    }
    cout << answer << '\n';
}

int32_t main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie();

    // freopen("input.txt", "r", stdin);

    int T = 1; 
    while(T--){
        solve();
    }
}