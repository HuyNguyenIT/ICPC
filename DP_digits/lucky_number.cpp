//https://www.spoj.com/problems/NUMTSN/
#include<bits/stdc++.h>

using namespace std;

int const N = 1e5 + 123;

void TestCase(){
	string N; cin >> N;
	int len =  N.size();
	N = "0" + N;
	long long f1[20][2][10]; // so chu so loc phat
	long long f2[20][2][10]; // so chu so chua so loc phat
	memset(f1, 0, sizeof(f1)); memset(f2, 0, sizeof(f2));
	f1[0][0][0] = 1; f2[0][0][0] = 0;
	for (int i = 0; i < len; i++){
		for(int lower = 0; lower < 2; lower++){
			for(int remaind = 0; remaind < 8; remaind++){
				for(int next = 0; next < 10; next++){
					if (next > N[i + 1] - '0' && lower == 0) continue;
					int lower2 = lower;
					if(lower == 0 && next == N[i + 1] - '0') lower2 = 0;
					if(lower == 0 && next < N[i + 1] - '0') lower2 = 1;
					int remaind2 = remaind * 10 + next;
					remaind2 %= 8;
					
					if(next != 6 && next != 8){
						f2[i + 1][lower2][remaind2] += f2[i][lower][remaind];
						f1[i + 1][lower2][remaind2] += f1[i][lower][remaind];
					} else {
						f2[i + 1][lower2][remaind2] += f2[i][lower][remaind] + f1[i][lower][remaind];
						f1[i + 1][lower2][remaind2] += f1[i][lower][remaind];
					}
				}
			}
		}
	}
	
	cout << f2[len][0][0] + f2[len][1][0] << '\n';
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(); cout.tie();
	int T = 1; cin >> T;
	while(T--){
		TestCase();
	}
}



