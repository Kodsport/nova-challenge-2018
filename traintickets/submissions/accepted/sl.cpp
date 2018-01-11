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
	Node *L, *R;
	int lo, hi;
	int res[12][12];
	Node(int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 == hi) {
			L = R = nullptr;
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
		} else {
			int mid = (lo + hi) / 2;
			L = new Node(lo, mid);
			R = new Node(mid, hi);
			combine(L->res, R->res, res);
		}
	}
	void combine(int A[12][12], int B[12][12], int C[12][12]) {
		rep(i,0,12) rep(j,0,12) {
			int c = inf;
			rep(k,0,12) c = min(c, A[i][k] + B[k][j]);
			C[i][j] = c;
		}
	}
	bool contains(int from, int to) {
		if (from >= hi || to <= lo) return false;
		return true;
	}
	void query(int from, int to, int out[12][12]) {
		assert(contains(from, to));
		if (!L) {
			memcpy(out, res, sizeof(res));
		} else {
			if (L->contains(from, to) && R->contains(from, to)) {
				int tempa[12][12], tempb[12][12];
				L->query(from, to, tempa);
				R->query(from, to, tempb);
				combine(tempa, tempb, out);
			} else if (L->contains(from, to)) {
				L->query(from, to, out);
			} else {
				R->query(from, to, out);
			}
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
	Node* tr = new Node(0, N);
	int Q;
	cin >> Q;
	rep(i,0,Q) {
		int a, b;
		cin >> a >> b;
		--a;
		int mat[12][12];
		tr->query(a, b, mat);
		cout << mat[0][0] << '\n';
	}

	flush(cout);
	exit(0);
}
