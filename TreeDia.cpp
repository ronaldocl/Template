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
using PII = pair<ll, ll>;
using VPII = vector<PII>;
template<typename T1, typename T2>
inline bool ckmax(T1& x, T2 y) { return y > x ? x = y, 1 : 0; }
template<typename T1, typename T2>
inline bool ckmin(T1& x, T2 y) { return y < x ? x = y, 1 : 0; }
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const ll M = 1e9 + 7;
/*--------------------------------------*/

class TreeDia {
public:
	VVI g;
	int n;
	int x, dia;
	TreeDia(VVI& _g) {
		g = _g;
		n = SZ(_g);
	}

	int solve(int u) {		
		x = 0;
		dia = 0;
		dfs(u, u, 0);
		dia = 0;
		dfs(x, x, 0);
		return dia;
	}	

	void dfs(int u, int p, int dep) {
		if(dep > dia) {
			dia = dep;
			x = u;
		}		
		for(auto& v: g[u]) if(v != p) dfs(v, u, dep + 1);
	}
};