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

class DSU {
public:
	const static int N = 1010;
	int p[N];
	int sz[N];
	DSU(int n) {
		for(int i = 0; i < n; ++i) p[i] = i;			
		for(int i = 0; i < n; ++i) sz[i] = 1;
	}

	int find_set(int x) {
		return p[x] == x ? x : p[x] = find_set(p[x]);
	}

	void union_set(int x, int y) {
		if(sz[x] > sz[y]) {
			sz[x] += sz[y];
			p[y] = x;
		}
		else {
			sz[y] += sz[x];
			p[x] = y;
		}
	}
};