#include<bits/stdc++.h>

using namespace std;

int const N = 1e5 + 111;

void TestCase(fstream &cin){
    int n; cin >> n;
    vector<int> v(n);
    for(auto&x : v) cin >> x;
    for(int i=0;i<n;i++){
        while(v[i]>=1 && v[i]<=n && v[i]!=v[v[i] - 1]){
            swap(v[i],v[v[i]-1]);
        }
    }
    for(int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    fstream cin("first-missing-positive.txt");
    int tt = 0; cin >> tt;
    while(tt--){
        TestCase(cin);
    }
}