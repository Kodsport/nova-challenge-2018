#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1000000000;

vector<array<int, 12>> costs;

struct Node {
	int res[12][12];
	Node(int lo) {
		const array<int, 12>& co = costs[lo];
		rep(i,0,12) {
			int dp[24];
			rep(j,0,24) dp[j] = inf;
			dp[i] = 0;
			rep(j,i,12) rep(k,0,12) {
				dp[j+k+1] = min(dp[j+k+1], dp[j] + co[k]);
			}
			rep(j,0,12) res[i][j] = dp[12+j];
		}
	}
};

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin.tie(nullptr);
	int N;
	cin >> N;
	costs.resize(N);
	rep(i,0,N) {
		rep(j,0,12) cin >> costs[i][j];
	}
	vector<Node> nodes;
	nodes.reserve(N);
	rep(i,0,N) nodes.emplace_back(i);
	int Q;
	cin >> Q;
	rep(i,0,Q) {
		int a, b;
		cin >> a >> b;
		--a;
		int dp[12], dp2[12];
		rep(i,0,12) dp[i] = inf;
		dp[0] = 0;
		rep(j,a,b) {
			rep(k,0,12) {
				int r = inf;
				rep(s,0,12) r = min(dp[s] + nodes[j].res[s][k], r);
				dp2[k] = r;
			}
			memcpy(dp, dp2, sizeof(dp));
		}
		cout << dp[0] << '\n';
	}

	flush(cout);
	exit(0);
}
