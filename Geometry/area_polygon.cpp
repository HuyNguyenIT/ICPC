#include<bits/stdc++.h>
using namespace std;

struct P{
    int x, y; 
    P midPoint(P p){
        return {(x + p.x), (y + p.y)};
    }
    
};

int sign(P p1, P p2){
	int dot = p1.x*p2.x + p1.y*p2.y ;
	int det = p1.x*p2.y - p1.y*p2.x;
	double angle = atan2(det, dot);
	if(angle > 0) return 1;
    else return -1;
}

bool equal(P p1, P p2){
    if(p1.x == p2.x && p1.y == p2.y) return true;
    return false;
}
bool cmp(P a, P b){
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
void TestCase(fstream &cin){
    int n; cin >> n;
    vector<P> v;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    int res = 0;
    for(int i = 0; i < n - 2; i++){
        res += 
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    fstream cin("area_polygon.txt");
    int tt = 1; cin >> tt;
    while(tt--){
        TestCase();
    }
}