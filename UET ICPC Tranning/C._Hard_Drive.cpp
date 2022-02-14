
#include<bits/stdc++.h>

using namespace std;

int const N = 1e6 + 123;

int check(vector<int> answer, int n){
    int res = 0;
    for(int i = 1; i < n; i++){
        if(answer[i] != answer[i - 1]) res += 1;
    }
    return res;
}

void solve(){
    int n, nbitChange, nBroken;
    cin >> n >> nbitChange >> nBroken;
    int store = nbitChange;
    vector<int> br(nBroken);
    for(auto&x : br) cin >> x, x--;
    vector<int> answer(n + 5, 0);
    for(int i = nBroken - 2; i >= -1; i--){
        int diff;
        int l, r;
        if(i == -1){
            diff = br[0] - 0;
            l = 0, r = br[0];
            int need = (nbitChange);
            int have = ((r - l) % 2 == 1) ? (r - l - 1) : (r - l);
            if(nbitChange % 2 == 1){
                answer[0] = 1;
                int cur = 0;
                if(need >= 1){
                    for(int iz = 1; iz < br[0]; iz++){
                        answer[iz] = !answer[iz - 1];
                        cur += 1;
                        if(cur == need){
                            break;
                        }
                    }
                }
                for(int iz = 0; iz < n; iz++) cout << answer[iz];
            } else {
                answer[0] = 0;
                int cur = 0;
                if(need > 0){
                    for(int iz = 1; iz < br[0]; iz++){
                        answer[iz] = !answer[iz - 1];
                        cur += 1;
                        if(cur == need){
                            break;
                        }
                    }
                }
                for(int iz = 0; iz < n; iz++) cout << answer[iz];
            }
            return;
        }else {
            diff = br[i + 1] - br[i];
            l = br[i], r = br[i + 1];
        }
        if(diff == 1) continue;
        int add = (diff % 2 == 1) ? (diff - 1) : (diff);
        if(add <= nbitChange){
            for(int iz = l + 1; iz < r; iz++){
                answer[iz] = !answer[iz - 1];
            }
            nbitChange -= add;
        }else {
            int need = 0;
            int target = ((nbitChange % 2 == 1) ? (nbitChange - 1) : (nbitChange));
            if(target != 0){
                for(int iz = l + 1; iz < r; iz++){
                    answer[iz] = !answer[iz - 1];
                    need += 1;
                    if(iz == r - 1){
                        if(answer[iz] == 1) need += 1;
                    }
                    if(need == target)break;
                }
                nbitChange -= need;
            }
            if(nbitChange % 2 == 1) answer[0] = 1;
            for(int iz = 0; iz < n; iz++) cout << answer[iz];
            return;
        }
    }
    if(nbitChange % 2 == 1) {
        answer[0] = 1;
    }
    for(int iz = 0; iz < n; iz++) cout << answer[iz];
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