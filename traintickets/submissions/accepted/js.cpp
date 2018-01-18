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

vi simplify(const vi& prices) {
    vi combined(13);
    for (int months = 1; months <= 12; ++months) {
        combined[months] = prices[months];
        for (int previous = 1; previous < months; previous++) {
            combined[months] = min(combined[months], combined[months - previous] + prices[previous]);
        }
    }
    return combined;
}

struct YearPrice {

    vi monthPrices;
    vi combinedPrices;

    YearPrice(const vi& monthPrices) : monthPrices(monthPrices) {
        combinedPrices = simplify(monthPrices);
    }

    int yearCost() const {
        return combinedPrices[12];
    }

    // The cost of paying for month [startMonth, 12] in year one
    // and [1, secondMonth) in year two.
    int costIntoNextYear(int startMonth, int secondMonth, const YearPrice& nextYear) const {
        int ans = 1e9;
        int firstYearMonths = 12 - startMonth + 1;
        for (int combinedFirstYear = 0; combinedFirstYear <= firstYearMonths; ++combinedFirstYear) {
            int remainingFirstYear = firstYearMonths - combinedFirstYear;
            int remainingSecondYear = secondMonth - 1;

            int remaining = remainingFirstYear + remainingSecondYear;
            if (remainingFirstYear) {
                for (int fixedTicket = remainingFirstYear; fixedTicket <= min(remaining, 12); ++fixedTicket) {
                    
                    int leftSecondYear = remaining - fixedTicket;

                    int price = combinedPrices[combinedFirstYear] + monthPrices[fixedTicket] + nextYear.combinedPrices[leftSecondYear];
                    ans = min(price, ans);
                }
            } else {
                int price = combinedPrices[combinedFirstYear] + nextYear.combinedPrices[remainingSecondYear];
                ans = min(price, ans);
            }
        }
        return ans;
    }

};

struct Transition {

    array<array<int, 14>, 14> cache;

    Transition() {}

    Transition(const YearPrice& a, const YearPrice& b) {
        rep(i,0,14) rep(j,0,14) cache[i][j] = 1e9;
        for (int firstMonth = 1; firstMonth <= 12; ++firstMonth) {
            for (int secondMonth = 1; secondMonth <= 13; ++secondMonth) {
                cache[firstMonth][secondMonth] = a.costIntoNextYear(firstMonth, secondMonth, b);
            }
        }
    }

    Transition(const Transition& a, const Transition& b) {
        rep(i,0,14) rep(j,0,14) cache[i][j] = 1e9;
        for (int firstMonth = 1; firstMonth <= 12; ++firstMonth) {
            for (int secondMonth = 1; secondMonth <= 13; ++secondMonth) {
                int ans = 1e9;
                for (int mid = 1; mid <= 12; ++mid) {
                    int price = a.cost(firstMonth, mid) + b.cost(mid, secondMonth);
                    ans = min(ans, price);
                }
                cache[firstMonth][secondMonth] = min(
                        cache[firstMonth][secondMonth], ans);
            }
        }
    }

    // Represents the cost of purchasing tickets from
    // [firstMonth in the first year, secondMonth in the second year)
    int cost(int firstMonth, int secondMonth) const {
        return cache[firstMonth][secondMonth];
    }

    int yearCost() {
        return cost(1, 13);
    }

};

struct Tree {
    Transition val;
    int L, R;
    Tree *left, *right;

    Tree(const vector<Transition>& transitions) : Tree(transitions, 0, sz(transitions)) {}

    Tree(const vector<Transition>& transitions, int lo, int hi) {
        L = lo;
        R = hi;
        if (R - L > 1) {
            int M = (L + R) / 2;
            left = new Tree(transitions, lo, M);
            right = new Tree(transitions, M, hi);
            val = Transition(left->val, right->val);
        } else {
            val = transitions[lo];
        }
    }

    Transition query(int lo, int hi) {
        //cout << "searching for [" << lo << ", " << hi << ") " << "in [" << L << ", " << R << ")" << endl;
        if (lo == L && hi == R) return val;
        int M = (L + R) / 2;
        if (hi <= M) {
            return left->query(lo, hi);
        }
        if (lo >= M) {
            return right->query(lo, hi);
        }
        return Transition(query(lo, M), query(M, hi));
    }
};

signed main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
    int N;
    cin >> N;
    vector<YearPrice> prices;
    rep(i,0,N) {
        vi p(13);
        rep(j,1,13) cin >> p[j];
        prices.emplace_back(p);
    }
    vector<Transition> transitions;
    rep(i,0,N - 1) {
        transitions.emplace_back(prices[i], prices[i + 1]);
    }
    Tree T(transitions);

    int Q;
    cin >> Q;
    rep(i,0,Q) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (a == b) cout << prices[a].yearCost() << endl;
        else cout << T.query(a, b).yearCost() << endl;
    }
    exit(0);
}
