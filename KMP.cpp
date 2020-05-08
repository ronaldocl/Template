#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i=a; i<n;  ++i)
#define per(i, n, a) for(int i=n; i>=a; --i)
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define SZ(a) int(a.size())
using ll = long long;
using ld = double;
using VI = vector<int>;
using VVI = vector<VI>;
using VD = vector<ld>;
using VVD = vector<VD>;
using PII = pair<int, int>;
const ll M = 20071027;
/*-------------------------------*/


struct KMP{
	void GetPre(string& s, VI& pre){
		int n = SZ(s);
		pre.resize(n);
		int k = -1;  pre[0] = -1;
		rep(i, 1, n){
			while(k != -1 && s[k+1] != s[i]) k = pre[k];
			if(s[k+1] == s[i]) k ++;
			pre[i] = k;
		}
	}
	
	bool Match(string& s, string& p){
		VI pre;
		GetPre(p, pre);
		int n = SZ(s), m = SZ(p);
		int k = -1;
		rep(i, 0, n){
			while(k != -1 && s[i] != p[k+1]) k = pre[k];
			if(s[i] == p[k+1]) k ++;
			if(k == m-1){   
				return true;    // find p in s    
			}
		}
		return false;
	}
};
