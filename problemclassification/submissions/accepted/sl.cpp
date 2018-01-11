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
	map<string, int> cats;
	map<string, vi> ma;
	rep(i,0,N) {
		string name, w;
		cin >> name;
		cats[name] = i;
		int k;
		cin >> k;
		rep(j,0,k) {
			cin >> w;
			ma[w].push_back(i);
		}
	}

	string word;
	vi count(N);
	while (cin >> word) {
		trav(x, ma[word]) count[x]++;
	}
	int max = *max_element(all(count));
	trav(pa, cats) {
		if (count[pa.second] == max) cout << pa.first << endl;
	}
	exit(0);
}
