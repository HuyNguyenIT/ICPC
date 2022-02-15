#include <bits/stdc++.h> 

using namespace std; 
 
string t, p; 
int k; 

void KMPPreprocess(string p, vector<int>& prefix) {
	prefix[0] = 0;
	int m = p.length();
	int j = 0;
	int i = 1;
	while (i < m) {
		if (p[i] == p[j]) {
			j++;
			prefix[i] = j;
			i++;
		}
		else {
			if (j != 0) {
				j = prefix[j - 1];
			}	
			else { // if (j == 0)
				prefix[i] = 0;
				i++;
			}
		}
	}
}

int KMPSearch(string t, string p, vector<int> prefix) {
	int n = t.length();
	int m = p.length();
	int cnt = 0; 
	int i = 0, j = 0;
	while (i < n) {
		if (p[j] == t[i]) {
			j++;
			i++;
		}
		if (j == m) {
			cnt++; 
			j = prefix[j - 1];
		}
		else {
			if (i < n && p[j] != t[i]) {
				if (j != 0) {
					j = prefix[j - 1];
				}
				else {
					i = i + 1;
				}
			}
		}
	}

  return cnt;  
} 
             
int main () {
	
	getline(cin, t); 
	getline(cin, p);
	cin >> k; 

	int l = 0; 
	int r = (int) p.length() - 1;

	string ans = "IMPOSSIBLE"; 
 	while (l <= r) {
 		int mid = (l + r) / 2; 
 		string tmp = "";
 		for (int i = 0; i <= mid; i++) {
 			tmp += p[i]; 
 		} 

 		vector <int> prefix(tmp.length()); 
 		KMPPreprocess(tmp, prefix);

 	 	int cnt = KMPSearch(t, tmp, prefix); 

 		if (cnt >= k) {
 			ans = tmp; 
 			l = mid + 1;
 		}
 		else {
 			r = mid - 1; 
 		}
 	}

 	cout << ans; 
	return 0; 
}