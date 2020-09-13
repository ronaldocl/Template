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
const ll M = 1e9 + 7;
/*--------------------------------------*/

class AC {
public:
    const static int MAXN = 1010;
    const static int MAXC = 26;
    int g[MAXN][MAXC], sz;  // trie goto
    int f[MAXN];            // suffix link
    int out[MAXN];          // output link   
    int val[MAXN];          // node value 

    AC() {
        memset(g[0], 0, sizeof(g[0]));
        val[0] = 0; f[0] = 0; sz = 1;
    }

    void insert(string& s) {
        int u = 0, n = SZ(s);
        rep(i, 0, n){
            int c = s[i] - 'a';
            if(!g[u][c]){
                memset(g[sz], 0, sizeof(g[sz]));
                val[sz] = 0;
                out[sz] = 0;
                g[u][c] = sz++;
            }
            u = g[u][c];
        }
        val[u] ++;
    }

    void build() {
        queue<int> q;
        rep(c, 0, MAXC){
            if(g[0][c]) q.push(g[0][c]), f[g[0][c]] = 0;
        }
        while(!q.empty()) {
            int state = q.front(); q.pop();
            rep(c, 0, MAXC) {
                if(g[state][c]) {
                    int v = f[state];
                    while(v && !g[v][c]) v = f[v];
                    f[g[state][c]] = g[v][c];
                    out[g[state][c]] = val[g[v][c]] ? g[v][c] : out[g[v][c]];
                    q.push(g[state][c]);
                }
            }   
        }
    }

    int find(string& s) {
        int u = 0, n = SZ(s);
        int ans = 0;
        rep(i, 0, n){
            int c = s[i] - 'a';
            while(u && !g[u][c]) u = f[u]; 
            u = g[u][c];
            int v = u;
            while(v) ans += val[v], val[v] = 0, v = out[v];
        }
        return ans;
    }
};


int main() {

    AC ac;

    return 0;
}