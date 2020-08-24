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
using VI = vector<ll>;
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

const int N = 10000000;
ll a[N];
ll cnt;

void merge_sort(int l, int r){
	if(l == r) return;

    int x = l + (r - l) / 2;
    merge_sort(l, x);
    merge_sort(x + 1, r);

	int n = x - l + 1, m = r - x;
    VI b(n, 0), c(m, 0);
    rep(i, 0, n) b[i] = a[i + l];
    rep(i, 0, m) c[i] = a[i + x + 1];

	int k = l, i = 0, j = 0;
	while(i < n && j < m){
		if(b[i] <= c[j]) a[k ++] = b[i++];
		else{
			cnt += n - i;
			a[k ++] = c[j ++];
		}
	}

	while(i < n) a[k++] = b[i++];
	while(j < m) a[k++] = c[j++];
}


int main(){

    int T; scanf("%d", &T);
    while(T --){
        int n; scanf("%d", &n);
        rep(i, 0, n) cin >> a[i];        
        cnt = 0;
        merge_sort(0, n - 1);
        cout << cnt << endl;
    }

	return 0;
}
