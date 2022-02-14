/* Gaurav Arora */
//**********************************************************TEMPLATE START******************************************************************
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename num_t>
// using ordered_set = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
using namespace chrono;
#define gc getchar_unlocked
#define inf INT_MAX
#define minf INT_MIN
#define ff first
#define ss second
#define mp make_pair
#define nline "\n"
#define pb push_back
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define msb(x) (31 - __builtin_clz(x))      
#define msbll(x) (63 - __builtin_clzll(x))  
#define NoSetbitsll(x) __builtin_popcountll(x)
#define setminus(x) memset(x, -1, sizeof(x))
#define setzero(x) memset(x, 0, sizeof(x))
#define f(i, n) for (i = 0; i < n; i++)
#define fe(i,n) for (i = 1; i <=n; i++)
#define fos(i, s, n, k) for (i = s; i < n; i = i + k)
#define fom(i, s, n, k) for (i = s; i < n; i = i * k)
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());} // for Vector v
#define printPrecision(p, Value) cout << fixed << setprecision(p) << Value
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vpi> vvpi;
typedef vector<vpl> vvpl;
typedef vector<bool> vb;
 
#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define deb(x)
#endif
#pragma warning disable format
 
//Debugger
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
 
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
// template <class T> void _print(ordered_set<T> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
ll gcd(ll a, ll b) { if (b > a) { return gcd(b, a); } if (b == 0) { return a; } return gcd(b, a % b); }
ll powm(ll a, ll b, ll mod) { ll res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }  //power modulo m
void extendgcd(ll a, ll b, ll* v) { if (b == 0) { v[0] = 1; v[1] = 0; v[2] = a; return; } extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return; } //pass an array of size 3
ll mminv(ll a, ll b) { ll arr[3]; extendgcd(a, b, arr); return arr[0]; } //for non prime b
ll mminvprime(ll a, ll b) { if (a % b == 0) return -1; return powm(a, b - 2, b); } //for prime only
vector<ll> sieve(int n) { int* arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) { vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1; } return vect; }
vector<string> split(string s, char delimeter) { vector <string> tokens; stringstream check1(s); string intermediate; while (getline(check1, intermediate, delimeter)) { tokens.push_back(intermediate); } return tokens; }
//Idiot consider all zeroes
string stringRemZeroes(string s) { string res; bool flag = true; for (int i = 0;i < s.length();i++) { if (s[i] == '0' && flag) continue; else { flag = false; res.push_back(s[i]); } } if (res.size() == 0) res = "0"; return res; }
void toLower(string& s) { transform(s.begin(), s.end(), s.begin(), ::tolower); }
void toUpper(string& s) { transform(s.begin(), s.end(), s.begin(), ::toupper); }
ll addm(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mulm(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll subm(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
// ll divm(ll a, ll b, ll m) { a = a % m; b = b % m; return (mulm(a, mminvprime(b, m), m) + m) % m; }  //only for prime m
const ll SIZE = 25; // change size before calling
ll fact[SIZE], ifact[SIZE];
void gen_factorial(ll n, ll mod) { fact[0] = fact[1] = ifact[0] = ifact[1] = 1; for (ll i = 2; i <= n; i++) { fact[i] = (i * fact[i - 1]) % mod; } ifact[n] = mminvprime(fact[n], mod); for (ll i = n - 1; i >= 2; i--) { ifact[i] = ((i + 1) * ifact[i + 1]) % mod; } }
ll choose(ll n, ll r, ll m) { ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m; } //First make fact and ifact for this to work both ll
//Range intersection
pi intersection(pi a, pi b) { if (a.first > b.second || a.second < b.first) { return mp(-1, -1); } else { b.first = max(b.first, a.first); b.second = min(b.second, a.second); } return b; }
pl findRatio(ll a, ll b) { ll g = gcd(a, b); a /= g; b /= g; return mp(a, b); }
ll stringToNo(string s) { stringstream din(s); ll x; din >> x; return x; }
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
template <typename T> void amax(T& a, T b) { a = max(a, b); }
template <typename T> void amin(T& a, T b) { a = min(a, b); }
ll i, j, k;
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
#pragma warning restore format

int dp[200005][2];
void dfs(int i, int parent, vvi& arr)
{
  deb(i);
  int sum = 0;
  for (auto x : arr[i])
  {
    if (x == parent)
      continue;
    deb(mp(i, x));
    dfs(x, i, arr);
    sum += max(dp[x][0], dp[x][1]);
  }
  dp[i][0] = sum;
  deb(mp(i, sum));
  for (auto x : arr[i])
  {
    if (x == parent)
      continue;
    dp[i][1] = max(dp[i][1], 1 + sum - max(dp[x][0], dp[x][1]) + dp[x][0]);
  }
}
void solve()
{
  int n;
  cin >> n;
  vvi arr(n);
  f(i, n - 1)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    arr[u].push_back(v);
    arr[v].push_back(u);
  }
  deb(arr);
  memset(dp, 0, sizeof dp);
  dfs(0, -1, arr);
  cout << max(dp[0][0], dp[0][1]);
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("Error.txt", "w", stderr);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}