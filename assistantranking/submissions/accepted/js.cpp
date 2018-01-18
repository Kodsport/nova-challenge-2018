#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	trav(e,g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    int N, K;
    cin >> N >> K;
    vector<vi> ed(3 * N); // items, lower ranks, upper rank

#define ITEM(x) x
#define LOWER(x) ((x) + ITEM(N))
#define UPPER(x) ((x) + LOWER(N))

    vector<pii> lranks(N), hranks(N);
    rep(i,0,N) {
        cin >> lranks[i].first;
        lranks[i].second = i;
    }
    rep(i,0,N) {
        cin >> hranks[i].first;
        hranks[i].second = i;
    }
    sort(all(lranks));
    sort(all(hranks));

    rep(i,0,N-1) {
        ed[LOWER(i)].push_back(LOWER(i + 1));
        ed[UPPER(i)].push_back(UPPER(i + 1));
    }

    rep(i,0,N) {
        ed[LOWER(i)].push_back(ITEM(lranks[i].second));
        ed[UPPER(i)].push_back(ITEM(hranks[i].second));
        
        int lb = lranks[i].first + K + 1;
        int hb = hranks[i].first + K + 1;

        int lp = lower_bound(all(lranks), pii(lb, 0)) - lranks.begin();
        int hp = lower_bound(all(hranks), pii(hb, 0)) - hranks.begin();


        if (lp != N) ed[ITEM(lranks[i].second)].push_back(LOWER(lp));
        if (hp != N) ed[ITEM(hranks[i].second)].push_back(UPPER(hp));
    }

    int ans = 0;
    scc(ed, [&](vi& comp) { 
        bool wc = 0;
        trav(it, comp) {
            if (it < N) wc = true;
        }
        ans += wc;
    });
    cout << ans << endl;

}
