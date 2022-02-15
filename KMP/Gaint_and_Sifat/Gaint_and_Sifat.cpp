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

int main() {
    int testCase;
    cin >> testCase;
    cin.ignore(256, '\n');
    for (int i = 1; i <= testCase; i++) {
        string t, p;
        getline(cin, t);
        getline(cin, p);
        t.erase(remove_if(t.begin(), t.end(), ::isspace), t.end());
        p.erase(remove_if(p.begin(), p.end(), ::isspace), p.end());
        // t = regex_replace(t, regex("\\s+"), "");
        // p = regex_replace(p, regex("\\s+"), "");
        vector<int> prefix(p.length());
        KMPPreprocess(p, prefix);
        printf("Case %d: %d\n", i, KMPSearch(t, p, prefix));
    }
    return 0;
}