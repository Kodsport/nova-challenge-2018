#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
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
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, K;
	cin >> N >> K;
	vi a[2];
	vector<pii> ai[2];
	rep(k,0,2) {
		a[k].resize(N);
		ai[k].resize(N);
		rep(i,0,N) cin >> a[k][i], ai[k][i] = pii(a[k][i], i);
		sort(all(ai[k]));
	}
	vector<vi> gr(3*N);
	rep(i,0,N-1) {
		gr[i+N*1].push_back(i+N*1+1);
		gr[i+N*2].push_back(i+N*2+1);
	}
	rep(k,0,2) rep(i,0,N) {
		auto pa = ai[k][i];
		int x = pa.first, ind = pa.second;
		int a2 = (int)(upper_bound(all(ai[k]), pii(x + K, INT_MAX)) - ai[k].begin());
		if (a2 != N) gr[ind].push_back(a2 + N*(k+1));
		gr[i + N*(k+1)].push_back(ind);
	}

	int res = 0;
	scc(gr, [&](vi& v) {
		bool y = false;
		trav(x, v) if (x < N) y = true;
		if (y) res++;
	});
	cout << res << endl;
	exit(0);
}
