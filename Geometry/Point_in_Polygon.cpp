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
        if(x * b.y > y * b.x) return 1;
        if(x * b.y == y * b.x) return 0;
        else return -1;
    }

    int triagle(P p1, P p2){
        return (p1 - *this) * (p2 - *this);
    }
};


bool intersect(P p1, P p2, P p3, P p4){
    if((p2 - p1) * (p4 - p3) == 0){ 
        if(p1.triagle(p2, p3) != 0){
            return false;
        }
        for(int i = 0; i < 2; i++){
            if(max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)){
                return false;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        return true;
    }

    for(int i = 0; i < 2; i++){
        int x = (p2 - p1) * (p3 - p1);
        int y = (p2 - p1) * (p4 - p1);
        if((x < 0 && y < 0) || (x > 0 && y > 0)) {
            return false;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    return true;
}

bool segment_contains(P a, P b, P c){
    if(a.triagle(b, c)) return false;
    if(min(a.x, b.x) <= c.x && max(a.x, b.x) >= c.x && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y)) return true;
    return false;
}

void solve(){
    int n; cin >> n; P a; a.read();
    vector<P> points;
    for(int i = 0; i < n; i++){
        P p; p.read();
        points.push_back(p);
    }

    for(int rep = 0; rep < 1; rep++){
        P p = a;
        P out = P{p.x + 1, 3000000001LL};
        bool is_on_boundary = false;
        
        int count = 0;
        for(int i = 0; i < n; i++){
            
            if(intersect(points[i], (i + 1 < n) ? points[i + 1] : points[0], p, out)) count += 1;
            if(segment_contains(points[i], (i + 1 < n) ? points[i + 1] : points[0], p)) {
                is_on_boundary = true;
                break;
            }
        }
        if(is_on_boundary) {
            cout << "0\n";
            continue;
        }
        if(count % 2 == 0){
            cout << "0\n";
        } else cout << "1\n";
    }
}

int32_t main(){
    ios_base :: sync_with_stdio(false);
    cin.tie();
    cout.tie();
    // freopen("input.txt", "r", stdin);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0 ;
}