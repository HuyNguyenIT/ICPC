#include <bits/stdc++.h>

using namespace std;

 

bool palindrome(string s){
    int l = 0, r = s.size() - 1;
    while(l <= r){
        if(s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    bool check = palindrome(s);

    if(k <= 0){
        cout << 1 << '\n';
    } else if(k <= 1){
        if(check){
            cout << 1 << '\n';

        } else {
            cout << 2 << '\n';
        }
    } else {
        if(check){
            cout << 1 << '\n';
        }
        else cout << 2 << '\n';
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