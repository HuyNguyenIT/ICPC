#include<iostream>
#include<vector>
#include<string>
using namespace std;

void KMPPreprocess(string& p, vector<int>& kmp) {
	kmp[0] = 0;
	int m = kmp.size();
	int j = 0;
	int i = 1;
	while (i < m) {
		if (p[i] == p[j]) {
			j++;
			kmp[i] = j;
			i++;
		}
		else {
			if (j != 0)
				j = kmp[j - 1];
			else {
				kmp[i] = 0;
				i++;
			}
		}
	}
}

bool findElement(vector<int> &v, int start, int end, int elem){
    for(int i = start; i < end; ++i)
        if(v[i] == elem)
            return true;
    return false;
}

void printString(string& s, int end){
    for(int i = 0; i < end; ++i)
        cout << s[i];
}

int main(){
	string s;
	getline(cin, s);
	vector<int> kmp(s.length());
    KMPPreprocess(s, kmp);
    int x = kmp[s.length() - 1];
    if (x == 0)
        cout << "Just a legend";
    else if (findElement(kmp, 1, s.length() - 1, x))
        printString(s, x);
    else if (kmp[x - 1] == 0)
        cout << "Just a legend";
    else if (kmp[x - 1])
        printString(s, kmp[x -1]);
    else
        cout << "Just a legend";
    return 0;
}