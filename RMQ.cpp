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

namespace RMQ{
	const int MAX = 1000100;
	int f[MAX][32], e[32], n;

	void sparse_table(VI& arr){
		n = SZ(arr);
		rep(i, 0, 31) e[i] = 1 << i;   
		rep(i, 0, n) f[i][0] = arr[i];		
		for(int j=1; e[j] <= n; ++j)
			for(int i=0; i+e[j]-1 < n; ++i)
				f[i][j] = min(f[i][j-1], f[i+e[j-1]][j-1]);
	}

	int query(int l, int r){
		int k = 0;
		while(e[k+1] <= r-l+1) k++;
		return min(f[l][k], f[r-e[k]+1][k]);
	}
}



int main()
{
	random_device dev;
	mt19937 gen(dev());

	vector<int> arr{5, 4, 3, 2, 1, 1, 2, 3, 4, 5};
	rep(i, 0, SZ(arr)) cout << i << " "; cout << endl;
	rep(i, 0, SZ(arr)) cout << arr[i] << " "; cout << endl;
	RMQ::sparse_table(arr);
	rep(i, 0, 9){
		int x = gen() % SZ(arr);
		int y = gen() % SZ(arr);
		if(x > y) swap(x, y);
		printf("l = %d, r = %d, rmq = %d\n", x, y, RMQ::query(x, y));
	}

	return 0;
}
