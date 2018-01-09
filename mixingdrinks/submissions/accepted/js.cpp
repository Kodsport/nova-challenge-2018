#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
    int lo = 0;
    ll tans = 1;
    rep(i,1,N + 1) {
        while (lo < allowed[i]) {
            tans -= ans[lo];
            ++lo;
        }
        ans[i] = tans;
        tans += ans[i];
        cout << ans[i] << endl;
    }
    cout << ans.back() << endl;
}
