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

vi simplify(const vi& year) {
    vi res(13);
    rep(i,1,13) {
        int best = year[i];
        rep(j,1,i) {
            best = min(best, year[j] + res[i - j]);
        }
        res[i] = best;
    }
    return res;
}

vector<vi> combine(const vector<vi>& a, const vector<vi>& b) {
    vector<vi> res(13, vi(13));
    rep(i,1,13) rep(j,1,13) rep(k,1,13) {
        res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
    }
    return res;
}

vector<vi> toTransition(const vi& a, const vi& b) {
    vector<vi> res(13, vi(13));
    rep(i,1,13) rep(j,1,13) {
        int tt = 13 - i + j;
        int t = min(12, tt);
        rep(k,13 - i,t + 1) {
            res[i][j] = min(res[i][j], a[k] + b[tt - k]);
        }
    }
    return res;
}

struct Tree {
    vector<vi> val;
    int L, R;
    Tree *left, *right;

    Tree(const vector<vector<vi>>& transitions) : Tree(transitions, 0, sz(transitions)) {
    }

    Tree(const vector<vector<vi>>& transitions, int lo, int hi) {
        L = lo;
        R = hi;
        if (R - L > 1) {
            int M = (L + R) / 2;
            left = new Tree(transitions, lo, M);
            right = new Tree(transitions, M, hi);
            val = combine(left->val, right->val);
        } else {
            val = transitions[lo];
        }
    }

    vector<vi> query(int lo, int hi) {
        if (lo == L && hi == R) return val;
        int M = (L + R) / 2;
        if (hi <= M) {
            return left->query(lo, hi);
        }
        if (lo >= M) {
            return right->query(lo, hi);
        }
        return combine(query(lo, M), query(M, hi));
    }
};

signed main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
    int N;
    cin >> N;
    vector<vi> prices(N);
    rep(i,0,N) {
        vi p(13);
        rep(j,1,13) cin >> p[j];
        prices[i] = simplify(p);
    }
    vector<vector<vi>> transitions(N - 1);
    rep(i,0,N - 1) transitions[i] = toTransition(prices[i], prices[i + 1]);
    Tree T(transitions);

    int Q;
    cin >> Q;
    rep(i,0,Q) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if (a == b) cout << prices[a][12] << endl;
        cout << T.query(a, b)[1][12] << endl;
    }
}
