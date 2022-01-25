#include <bits/stdc++.h>

using namespace std;

void KMPPreprocess(string& p, vector<int> &prefix) {
    prefix[0] = 0;
    int m = p.length();
    int j = 0;
    int i = 1;
    while (i < m) {
        if (p[i] == p[j]) {
            j++;
            prefix[i] = j;
            i++;
        } else {
            if (j != 0) {
                j = prefix[j - 1];
            } else {
                prefix[i] = 0;
                i++;
            }
        }
    }
}
/*  p[i] is the longest standard prefix of the string p[1, i - 1]
    such that it is also a suffix of the string p[1, i]
*/
int KMPSearch(string& t, string& p, vector<int> &prefix) {
    int n = t.length();
    int m = p.length();
    int i = 0, j = 0, found = 0;
    while (i < n) {
        if (p[j] == t[i]) {
            j++;
            i++;
        }
        if (j == m) {
            found++;
            j = prefix[j - 1];
        } else if (i < n && p[j] != t[i]) {
            if (j != 0) {
                j = prefix[j - 1];
            } else {
                i++;
            }
        }
    }
    return found;
}

void TestCase(){
    string s = "ABABAD";
    vector<int> p(s.size() + 5);
    KMPPreprocess(s, p);
    for(int i = 0; i < s.size(); i++){
        cout << p[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(); cout.tie();
    int T = 1; 
    while(T--){
        TestCase();
    }
    return 0;
}