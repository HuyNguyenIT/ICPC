#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        if(n == 1) return true;
        for(int i = 0; i < n; i++){
            if(i == n - 1) return true;
            if(mx == 0) return false;
            mx--;
            mx = max(mx, nums[i + 1]);
        }
        return false;
    }
};

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto&x : v) cin >> x;
    cout << Solution().canJump(v) << '\n';
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(); cout.tie();
    freopen("input.txt", "r", stdin);
    int tt = 1; cin >> tt;
    while(tt--){
        solve();
    }
}

