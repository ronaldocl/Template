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

int n = 4;

string GetString(int x){
	string res;
	per(i, n-1, 0) res.push_back(((x >> i) & 1) + '0');
	return res;
}

void solve(){
	rep(mask, 0, 1 << n){
		// 枚举状态的子状态
		per(s, mask, 0){
			s &= mask;   // 关键语句
			printf("s = (%s) is a sub-state of mask = (%s)\n", GetString(s).c_str(), GetString(mask).c_str());
		}

		cout << "------------------------" << endl;

	}

}


int main(){
	solve();

	return 0;
}