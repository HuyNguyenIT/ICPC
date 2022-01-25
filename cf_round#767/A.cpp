#include<bits/stdc++.h>

using namespace std;

int const N = 1e5 + 111;

#define int long long

void TestCase(){
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for(auto&x : a) cin >> x;
    for(auto&x : b) cin >> x;
    vector<pair<int, int>> p;
    for(int i = 0; i < n; i++){
        p.push_back({a[i], b[i]});
    }
    sort(p.begin(), p.end());

    for(int i = 0; i < p.size(); i++){
        if(k >= p[i].first){
            k += p[i].second;
        } else break;
    }
    cout << k << '\n';
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