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
const ll M = 1e9 + 7;
/*--------------------------------------*/

const int MAXN = 500100;
const int SIGMA_SIZE = 26;
namespace AC{
	int ch[MAXN][SIGMA_SIZE], sz;
	int f[MAXN], val[MAXN];

	void Init(){
		sz = 1; memset(ch[0], 0, sizeof(ch[0]));
	}

	void Insert(string& s){
		int u = 0, n = SZ(s);
		rep(i, 0, n){
			int c = s[i] - 'a';
			if(!ch[u][c]){
				memset(ch[sz], 0, sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		val[u] ++;
	}

	void GetFail(){
		queue<int> q;
		f[0] = 0;
		rep(c, 0, SIGMA_SIZE){
			int u = ch[0][c];
			if(u) f[u] = 0, q.push(u);
		}
		while(!q.empty()){
			int r = q.front(); q.pop();
			rep(c, 0, SIGMA_SIZE){
				int u = ch[r][c];
				if(!u) continue;
				q.push(u);
				int v = f[r];
				while(v && !ch[v][c]) v = f[v];
				f[u] = ch[v][c];
			}
		}
	}

	int Find(string& s){
		int n = SZ(s);
		int k = 0, ans = 0;
		rep(i, 0, n){
			int c = s[i] - 'a';
			while(k && !ch[k][c]) k = f[k];
			k = ch[k][c];
			int t = k;
			while(t) ans += val[t], val[t] = 0, t = f[t];  // match found
		}
		return ans;
	}
}