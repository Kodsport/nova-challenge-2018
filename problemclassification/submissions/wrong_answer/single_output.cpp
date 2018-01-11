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

signed main() {
	cin.sync_with_stdio(0);
	int cat;
	cin >> cat;

	map<string, vector<string>> assoc;
	map<string, int> words;
	rep(i,0,cat) {
		string name;
		cin >> name;
		int an;
		cin >> an;
		words[name];
		rep(j,0,an) {
			string word;
			cin >> word;
			assoc[word].push_back(name);
		}
	}
	string word;
	while (cin >> word) {
		trav(it, assoc[word]) words[it]++;
	}
	int mx = 0;
	trav(it, words) smax(mx, it.second);
	trav(it, words) {
		if (it.second == mx) {
            cout << it.first << endl;
            break;
        }
	}
}
