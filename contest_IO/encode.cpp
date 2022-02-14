#include <bits/stdc++.h>

using namespace std;

#define int long long 

int solve(int a, int k) {
    while(a % 100 != 0 &&  k > 0 &&  a <= 100){
        a = a + a % 100;
        k--;
    }
    map<int, int> last_digit;
    map<int, int> last_k;
    map<int, int> last_a;

    int ok = -1;
    while(a % 100 != 0 && k > 0){
        if(last_digit[a % 100] != 0){
            ok = 1;
            break;
        } else{
            last_digit[a % 100] = 1;
            last_k[a % 100] = k;
            last_a[a % 100] = a;
        }
        a = a + a % 100;
        k--;
    }
    if(ok == 1){
        int k_last = last_k[a % 100];
        int a_last = last_a[a % 100];
        int diff_a = a - a_last;
        int diff_k = k_last - k;
        int time_k = k / diff_k;
        k = k % diff_k;
        a = a + diff_a * time_k;
        
    }
    while(a % 100 != 0 && k > 0){
        a = a + a % 100;
        k--;
    }
    return a;
}
 
int bruteForce(int a, int k){
    if(k > 1e8) {
        cout << "brute_tle\n";
        return a;
    }
    while(a % 100 == 0 || k > 0){
        a = a + a % 100;
        k--;
    }
    return a;
} 

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie();
    // freopen("input.txt", "r", stdin);
    int t = 1;
    std::cin >> t;
    
    while (t--) {
        int a, k; cin >> a >> k;
        // if(bruteForce(a, k) == solve(a, k)){
        //     cout << "AC\n";
        // } else {
        //     cout << "WA\n";
        // }
        cout << solve(a, k) << '\n';
    }
    
    return 0;
}