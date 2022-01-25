#include<bits/stdc++.h>

using namespace std;

int const N = 1e5 + 111;

#define int long long

int calc(int l, int r){
    int n = r - l + 1;
    if(l % 2 == 0 && r % 2 == 0){
        return (int)(n/2) + 1;
    } else if(l % 2 == 1 && r % 2 == 1){
        return (int)(n/2);
    } else return n/2;
}

void TestCase(){
    int l, r, k; cin >> l >> r >> k;
    if(r - l + 1 - calc(l, r) <= k){
        cout << "YES\n";
        return;
    }
    if(r - l + 1 == 1 && l > 1){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int32_t main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(0); cout.tie();
    // freopen("input.txt", "r", stdin);
    int tt; cin >> tt;
    while(tt--){
        TestCase();
    }
}