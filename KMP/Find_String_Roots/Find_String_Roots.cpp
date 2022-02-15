#include <bits/stdc++.h>

using namespace std;

void KMPPreprocess(string p, vector<int> &kmp) {
    kmp[0] = 0;
    int m = p.length();
    int j = 0;
    int i = 1;
    while (i < m) {
        if (p[i] == p[j]) {
            j++;
            kmp[i] = j;
            i++;
        } else {
            if (j != 0) {
                j = kmp[j - 1];
            } else {
                kmp[i] = 0;
                i++;
            }
        }
    }
}

int solve(string s) {
    vector<int> kmp(s.length());
    KMPPreprocess(s, kmp);
    int m = s.length();
    if (m % (m - kmp[m - 1])) {
        return 1;
    } else {
        return (m / (m - kmp[m - 1]));
    }
}

int main() {
    while (true) {
        string s;
        getline(cin, s);
        if (s == "*") break;
        cout << solve(s) << endl;
    }
    return 0;
}