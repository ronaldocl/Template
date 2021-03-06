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

struct TrieNode {
	int num;
	TrieNode* child[26];
	TrieNode(): num(0) {
		for(int i = 0; i < 26; ++i) child[i] = nullptr;
	}
};

class Trie {
public:
	const static int MAXN = 10100;
	const static int MAXC = 26;
	int g[MAXN][MAXC], sz;
	int val[MAXN];

	Trie() {
		sz = 1; memset(g[0], 0, sizeof(g[0]));
	}

	void insert(string& s) {
		int u = 0, n = SZ(s);
		rep(i, 0, n) {
			int c = s[i] - 'a';
			if(!g[u][c]){
				memset(g[sz], 0, sizeof(g[sz]));
				val[sz] = 0;
				g[u][c] = sz++;
			}
			u = g[u][c];
		}
		val[u] ++;
	}

	int find(string& s) {
		int u = 0, n = SZ(s);
		rep(i, 0, n) {
			int c = s[i] - 'a';
			if(!g[u][c]) return false;  // mismatch
			u = g[u][c];
		}	
		return val[u] > 0;  // 1-found, 0-not found
	}
};


int main() {
	Trie trie;

	return 0;
}