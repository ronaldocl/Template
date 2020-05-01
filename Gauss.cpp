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
const int M = 1e9 + 7;
/*-------------------------------*/


struct Gauss{
	VD solve(VVD A, VD b){
		assert(SZ(A) == SZ(b));
		int rows = SZ(A), cols = SZ(A[0]);
		assert(rows >= cols);
		
		rep(i, 0, cols){
			int largest = i;
			rep(j, i, rows) 
				if(abs(A[i][j]) > abs(A[largest][i])) largest = j;
			swap(A[i], A[largest]);  
			swap(b[i], b[largest]);

			rep(j, i+1, rows){
				int r = A[j][i] / A[i][i];
				rep(k, i, cols) A[j][k] -= A[i][k] * r;
				A[j][i] = 0;
				b[j] -= b[i] * r;
			}
		}
		VD ans(cols, 0);

		per(i, cols-1, 0){
			rep(j, 0, i) assert(A[i][j] == 0);

			rep(j, i+1, cols)  b[i] -= A[i][j] * ans[j];

			ans[i] = b[i] / A[i][i];
		}
		return ans;
	}
};



int main(){

	VVD A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
	VD b{0.5, 1.3, 2.5, 6.321};

	Gauss sol;

	VD res = sol.solve(A, b);

	for(auto& x: res) cout << x << " "; cout << endl;

	return 0;
}