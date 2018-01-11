#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	int mi = INT_MIN;
	int ma = INT_MAX;
	rep(i,0,N) {
		int a, b;
		cin >> a >> b;
		mi = max(mi, a);
		ma = min(ma, b);
	}
	if (mi <= ma) cout << "gunilla has a point" << endl;
	else cout << "edward is right" << endl;
	exit(0);
}
