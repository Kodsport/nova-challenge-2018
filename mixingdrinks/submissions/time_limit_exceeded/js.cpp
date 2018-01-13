#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1000000007;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    int N, B;
    cin >> N >> B;
    vector<int> allowed(N + 1, 0);
    rep(i,0,B) {
        int a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        allowed[a] = max(allowed[a], b);
    }
    vector<int> ans(N + 1);
    ans[0] = 1;
    rep(i,1,N + 1) {
        ll tans = 0;
        rep(j,allowed[i],i) tans += ans[j];
		tans %= mod;
        ans[i] = (int)tans;
    }
	ll res = ans.back() % mod;
	if (res < 0) res += mod;
    cout << res << endl;
}
