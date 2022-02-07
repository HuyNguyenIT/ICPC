#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
 
void solve() {
    int n, k; cin >> n >> k;

    bool check = (n * k % 2 == 0);
    int odd = 0, even = 0;
    if(check) {
        odd = even = n * k/2;
    } else {
        odd = n * k / 2 + 1;
        even = n * k / 2;
    }

    if(odd % k ==  0 && even % k == 0){
        int begin = 1;
        cout << "YES\n";
        for(int i = 1; i <= odd / k; i++){
            for(int j = 1; j <= k; j++){
                cout << begin << ' ';
                begin += 2;
            }
            cout << '\n';
        }
        begin = 2;
        for(int i = 1; i <= even / k; i++){
            for(int j = 1; j <= k; j++){
                cout << begin << ' ';
                begin += 2;
            }
            cout << '\n';
        }
    } else {
        cout << "NO\n";
    }
}
 
int main() {
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