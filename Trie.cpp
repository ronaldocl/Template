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

namespace TRIE{
	const int MAXN = 500100;
	const int SIGMA_SIZE = 26;
	int ch[MAXN][SIGMA_SIZE], sz;
	int val[MAXN];

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

	int Find(string& s){
		int u = 0, n = SZ(s);
		rep(i, 0, n){
			int c = s[i] - 'a';
			if(!ch[u][c]) return false;  // mismatch
			u = ch[u][c];
		}	
		return val[u] > 0;  // 1-found, 0-not found
	}
}