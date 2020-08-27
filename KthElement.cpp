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

// Find the kth element of an array in O(n)
class Solution
{
public:
    int find_Kth(int l, int r, int k, VI& a)
    {
        if (l == r) return a[l];

        int x = l + rnd() % (r - l + 1);
        swap(a[x], a[r]);

        int j = l - 1;
        for(int i = l; i < r; ++i) {
            if (a[i] < a[r]) swap(a[++j], a[i]);
        }        
        swap(a[++j], a[r]);
        if(j == k - 1) return a[j];
        if(j > k - 1) return find_Kth(l, j - 1, k, a);
        return find_Kth(j + 1, r, k, a);
    }
};


int main() {
    int n = 10000;
    VI a(n);
    for(auto& v: a) v = rnd();
    VI b(a);
    sort(all(b));

    Solution sol;
    int cnt = 0;
    rep(k, 1, n + 1) {
        int y = sol.find_Kth(0, n - 1, k, a);
        if(b[k - 1] != y) cnt ++;
    }
    assert(cnt == 0);
    
    return 0;
}
