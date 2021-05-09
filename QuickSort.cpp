#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i=a; i<n;  ++i)
#define per(i, n, a) for(int i=n; i>=a; --i)
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define SZ(a) int(a.size())
#define ffs __builtin_ffs
#define clz __builtin_clz
#define ctz __builtin_ctz
#define popcount __builtin_popcount
using ll = long long;
using ld = double;
using VI = vector<int>;
using VVI = vector<VI>;
using VD = vector<ld>;
using VVD = vector<VD>;
using VS = vector<string>;
using PII = pair<int, int>;
using VPII = vector<PII>; 
template<typename T1, typename T2>
inline bool ckmax(T1& x, T2 y) { return y > x ? x = y, 1 : 0; }
template<typename T1, typename T2>
inline bool ckmin(T1& x, T2 y) { return y < x ? x = y, 1 : 0; }
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int M = 1e9 + 7;
const int INF = 0x3f3f3f3f;
/*--------------------------------------*/

// recursive
void quick_sort_1(vector<int>& a, int l, int r) {
	if(l >= r) return ;

	int x = l + rand() % (r - l + 1);
	swap(a[x], a[r]);

	int j = l - 1;
	for(int i = l; i < r; ++i) {
		if(a[i] < a[r]) swap(a[++j], a[i]);
	}

	swap(a[++j], a[r]);

	quick_sort_1(a, l, j - 1);
	quick_sort_1(a, j + 1, r);
}

// non-recursive
void quick_sort_2(vector<int>& a) {
	int n = a.size();

	stack<pair<int, int> > st;
	st.push({0, n -1});
	while(!st.empty()) {
		auto u = st.top(); 
		st.pop();
		int l = u.first, r = u.second;

		if(l >= r) continue;

		int x = l + rand() % (r - l + 1);
		swap(a[x], a[r]);

		int j = l - 1;
		for(int i = l; i < r; ++i) {
			if(a[i] < a[r]) swap(a[++j], a[i]);
		}

		swap(a[++j], a[r]);

		st.push({l, j - 1});
		st.push({j + 1, r});
	}
}


void print(vector<int>& a) {
	for(auto x : a) cout << x << " ";
	cout << endl;
}

int main() {
	int T = 10;
	for(int cas = 0; cas < T; ++cas) {
		int n = rand() % 20;
		vector<int> a(n);
		for(int i = 0; i < n; ++i) a[i] = rand() % 100;
		print(a);
		quick_sort_2(a);
		print(a);
		cout << endl;
	} 

	return 0;
}