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
const ll M = 1e9 + 7;
/*-------------------------------*/


namespace ST{
	const int MAXN = 410;
	struct Node{
		int s, t;
		int val;
	}seg[4*MAXN];

	void build(int v, int s, int t){
		seg[v] = {s, t, 0};
		if(s == t) return ;
		int d = (s+t)>>1;
		build(v<<1, s, d);
		build(v<<1|1, d+1, t);
	}

	void maintain(int v){
		Node& p = seg[v];
		int nc = v<<1;

	}

	void update(int v, int s, int t, int val){
		Node& p = seg[v];
		if(s <= b[p.s] && b[p.t] <= t){

		}
		else{
			int d=(p.s+p.t)>>1;
			if(s <= d) update(v<<1, s, t, val);
			if(t > d) update(v<<1|1, s, t, val);	
		}
		maintain(v);
	}

	void read(int v, int s, int t){

	}
}


int main(){


	return 0;
}