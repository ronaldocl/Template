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
mt19937 rnd(random_device{}());
const ll M = 1e9 + 7;
/*--------------------------------------*/

class Solution {
public:
	int cnt;
	VI nums;
    int inversion(vector<int>& arr) {
    	nums = arr;
    	cnt = 0;
    	int n = SZ(arr);
    	merge_sort(0, n - 1, arr);

    	return cnt;
    }

    void merge_sort(int l, int r, VI &a){
    	if(l == r){
    		a = VI{nums[l]};
    		return ;
    	}
    	int x = l + (r - l) / 2;
    	int n = x - l + 1, m = r - x;
    	VI b(n), c(m);
    	merge_sort(l, x, b);
    	merge_sort(x + 1, r, c);

    	int k = 0, i = 0, j = 0;
    	while(i < n && j < m){
    		if(b[i] <= c[j]) a[k ++] = b[i++];
    		else{
    			cnt += x - l - i + 1;
    			a[k ++] = c[j ++];
    		}
    	}

    	while(i < n) a[k++] = b[i++];
    	while(j < m) a[k++] = c[j++];
    }
};


int main(){
	VVI a{
		{5, 4, 3, 2, 1},
		{1, 2, 3, 4},
		{3, 3, 2, 2, 2, 4}, 
		{1, 1},
		{1},
		{100, 99},
		{3, 2, 1, 5, 2, 1}
	};

	Solution sol;

	for(auto v: a) {
		cout << sol.inversion(v) << endl;
	}

	return 0;
}
