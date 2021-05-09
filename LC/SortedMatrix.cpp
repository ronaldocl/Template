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



vector<int> find_1(vector<vector<int>>& a, int val) {
	int m = a.size();
	if(m == 0) return vector<int>{-1, -1};

	int n = a[0].size();

	int r = m - 1, c = 0;
	while(r >= 0 && c < n) {
		if(val < a[r][c]) {
			r --;
		}
		else if(val > a[r][c]) {
			c ++;
		}
		else {
			return vector<int>{r, c};
		}
	}

	return vector<int>{-1, -1};
}

vector<int> find_2(vector<vector<int>>& a, int val) {
	
}



int main(){

	vector<vector<int>> a{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	int v = 6;

	auto res = find_1(a, v);

	printf("r = %d, c = %d\n", res[0], res[1]);	

    return 0;
}