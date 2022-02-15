#include <iostream>
#include <vector>
using namespace std;
void KMPPreprocess(vector<int> p, vector<int> & prefix) {
    int m = p.size();
    prefix.resize(m, 0);
    int j = 0;
    int i = 1;
    while (i < m) {
        if (p[i] == p[j]) {
            j++;
            prefix[i] = j;
            i++;
        }
        else {
            if (j != 0) j = prefix[j - 1];
            else {
                prefix[i] = 0;
                i++;
            }
        }
    }
}
int calc(vector<int> B, vector<int> A) {
    if (B.size() == 0) {
        return A.size() + 1;
    }

    vector<int>prefix;
    KMPPreprocess(B, prefix);

    int cnt = 0;

    int n = A.size();
    int m = B.size();
    int i = 0, j = 0;
    while (i < n) {
        if (B[j] == A[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cnt++;
            j = prefix[j - 1];
        }
        else if (i < n && B[j] != A[i]) {
            if (j != 0) {
                j = prefix[j - 1];
            } else {
                i++;
            }
        }
    }
    return cnt;
}

int main() {
    int n, w, x, y;
    vector<int> A, B;

    cin >> n >> w;

    A.resize(n - 1);
    cin >> x;
    for (int i = 0; i < n - 1; i++) {
        cin >> y;
        A[i] = y - x;
        x = y;
    }

    B.resize(w - 1);
    cin >> x;
    for (int i = 0; i < w - 1; i++) {
        cin >> y;
        B[i] = y - x;
        x = y;
    }

    cout << calc(B, A);

    return 0;

}