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
	int N, P;
	cin >> N >> P;
	vi ed(N);
	rep(i,0,P) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		if (a > b) swap(a, b);
		ed[b] = max(ed[b], a+1);
	}
	vector<ll> res(N+1), sumres(N+1);
	res[0] = 1;
	int howfar = 0;
	ll sumall = 0;
	rep(i,0,N) {
		sumall = (sumall + res[i]) % mod;
		sumres[i+1] = sumall;
		howfar = max(howfar, ed[i]);
		res[i+1] = (sumall - sumres[howfar]) % mod;
	}
	ll r = res[N] % mod;
	if (r < 0) r += mod;
	cout << r << endl;
	exit(0);
}
