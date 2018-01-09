#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define Min(...) min({__VA_ARGS__})
#define Max(...) max({__VA_ARGS__})
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
static inline ll sgn(ll x) { return (x>0)-(x<0); }
static inline bool vowel(char c) { c = (char)tolower(c); return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y'; }
static inline vi rvi(int N) { vi res(N); rep(i,0,N) cin >> res[i]; return res; }
static inline int ri() { int N; cin >> N; return N; }
static inline void pvi(const vi& r) { trav(it,r) cout << it << " "; cout << endl; }
template<class S, class T> static inline void smax(S& s, const T& t) { if (t > s) s = t; }
template<class S, class T> static inline void smin(S& s, const T& t) { if (t < s) s = t; }
template<class S> static inline void in(S& s) { cin >> s; }
template<class S> static inline void ut(const S& s) { cout << s << " "; }
static inline void nl() { cout << endl; }

const int MOD = 1000000009;

signed main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int N = ri(), l = ri();
	vi G = rvi(l);
	if (!is_sorted(all(G)) || G.back() != N) {
		ut(0); nl();
		return 0;
	}
	vi A(N);
	iota(all(A), 1);
	int ans = 0;
	do {
		vi res;
		rep(i,0,N) {
			if (res.empty() || A[i] > res.back()) res.push_back(A[i]);
		}
		ans += res == G;
	} while(next_permutation(all(A)));
	cout << ans << endl;
}
