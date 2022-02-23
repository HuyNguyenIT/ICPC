#include<bits/stdc++.h>
using namespace std;

#define int long long 

struct P{
    int x, y;
    void read(){
        cin >> x >> y;
    }
    
    P operator - (const P &b) const{
        return P{x - b.x, y - b.y};
    }

    void operator -= (const P &b){
        x -= b.x;
        y -= b.y;
    }

    P operator + (const P &b){
        return P{x + b.x, y + b.y};
    }

    int operator * (const P &b) const{
        return x * b.y - y * b.x;
    }

    int triagle(P p1, P p2){
        return (p1 - *this) * (p2 - *this) /2;
    }
};


void solve(){
    P p1, p2, p3, p4;
    p1.read(); p2.read(); p3.read(); p4.read();

    if((p2 - p1) * (p4 - p3) == 0){ 
        if(p1.triagle(p2, p3) != 0){
            cout << "NO\n";
            return;
        }
        for(int i = 0; i < 2; i++){
            if(max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)){
                cout << "NO\n";
                return;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        cout << "YES\n";
        return;
    }

    for(int i = 0; i < 2; i++){
        int x = (p2 - p1) * (p3 - p1);
        int y = (p2 - p1) * (p4 - p1);
        if((x < 0 && y < 0) || (x > 0 && y > 0)) {
            cout << "NO\n";
            return;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    cout << "YES\n";

}

int32_t main(){
    ios_base :: sync_with_stdio(false);
    cin.tie();
    cout.tie();
    // freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0 ;
}