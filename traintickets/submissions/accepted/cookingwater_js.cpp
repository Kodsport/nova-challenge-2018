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


template <class T>
auto addInterval(set<pair<T, T>>& is, T L, T R) {
	if (L == R) return is.end();
	auto it = is.lower_bound({L, R}), before = it;
	while (it != is.end() && it->first <= R) {
		R = max(R, it->second);
		before = it = is.erase(it);
	}
	if (it != is.begin() && (--it)->second >= L) {
		L = min(L, it->first);
		R = max(R, it->second);
		is.erase(it);
	}
	return is.insert(before, {L,R});
};

template <class T>
void removeInterval(set<pair<T, T>>& is, T L, T R) {
	if (L == R) return;
	auto it = addInterval(is, L, R);
	T r2 = it->second;
	if (it->first == L) is.erase(it);
	else (T&)it->second = L;
	if (R != r2) is.emplace(R, r2);
}


signed main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	set<pii> couldCook;
	couldCook.emplace(0, 1000);
	int N = ri();
	rep(i,0,N) {
		int L = ri();
		int last = 0;
		rep(k,0,L) {
			int a, b;
			cin >> a >> b;
			removeInterval(couldCook, last, a);
			last = b + 1;
		}
		removeInterval(couldCook, last, 1000);
	}
	if (couldCook.empty()) cout << "edward is right" << endl;
	else cout << "gunilla has a point" << endl;
}
