#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1000000007;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, L;
	cin >> N >> L;
	vi seq(L);
	vi used(N);
	rep(i,0,L) cin >> seq[i], --seq[i], used[seq[i]] = 1;
	rep(i,0,L-1) if (seq[i] >= seq[i+1]) {
		cout << 0 << endl;
		return 0;
	}
	if (seq.back() != N-1) {
		cout << 0 << endl;
		return 0;
	}

	ll res = 1;
	int before = 0;
	for (int i = N; i--;) if (!used[i]) {
		int pos = (int)(lower_bound(all(seq), i) - seq.begin());
		assert(pos != sz(seq));
		res = res * (sz(seq) - pos + before) % mod;
		before++;
	}

	cout << res << endl;
	exit(0);
}
