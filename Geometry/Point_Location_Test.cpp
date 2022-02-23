#include<bits/stdc++.h>
using namespace std;

#define int long long 

struct P{
    int x, y;
    void read(){
        cin >> x >> y;
    }
    
    P operator - (const P &b) const{
        return {x - b.x, y - b.y};
    }

    void operator -= (const P &b){
        x -= b.x;
        y -= b.y;
    }

    P operator + (const P &b){
        return {x + b.x, y + b.y};
    }

    long long operator * (const P &b) const{
        return x * b.y - y * b.x;
    }
};


void solve(){
    P p1, p2, p3;
    p1.read(); p2.read(); p3.read();
    p2 -= p1;
    p3 -= p1;

    int cross_product = p2 * p3;
    if(cross_product == 0){
        cout << "TOUCH\n";
    } else if(cross_product > 0){
        cout << "LEFT\n";
    } else cout << "RIGHT\n";
}

int32_t main(){
    ios_base :: sync_with_stdio(false); cin.tie(); cout.tie();
    // freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0 ;
}