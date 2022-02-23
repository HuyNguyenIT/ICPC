#include<bits/stdc++.h>
using namespace std;

// tim phan tu xa nhat ve phia ben trai ma lon hon x

vector<int> processLeft(vector<int> &a){
    stack<int> st;
    int n = a.size();
    vector<int> L(n + 5);
    for (int i = 0;i < n; i++){
        while (!st.empty() && a[st.top()] >= a[i]){
            st.pop();
        }
        if (st.empty()){
            L[i] = 0;
        }else{
            L[i] = st.top() + 1;
        }
        st.push(i);
    }
    return L;

}
// tim phan tu xa nhat ve phia ben phai lon hon x
vector<int> processRight(vector<int> &a){
    stack<int> st;
    int n = a.size();
    vector<int> R(n + 5);
    for (int i = n - 1; i >= 0; i--){
        while (!st.empty() && a[st.top()] >= a[i]){
            st.pop();
        }
        if (st.empty()){
            R[i] = n-1;
        }else{
            R[i] = st.top() - 1;
        }
        st.push(i);
    }
    return R;

}




int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(); cout.tie();
    freopen("input.txt", "r", stdin);
    int n; cin >> n; vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> left = processLeft(v);
    vector<int> right = processRight(v);

    for(int i = 0; i < n; i++){
        cout << left[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < n; i++){
        cout << right[i] << ' ';
    }
    

}