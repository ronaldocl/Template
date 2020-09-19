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
 
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(bool b) { return (b ? "true" : "false"); }
 
template <size_t N>
string to_string(bitset<N> v) { ostringstream oss; oss<<v; return oss.str(); }
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; 
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename T>
string to_string(T& v) {
    string res="{", sep; for(const auto& x:v) res+=sep+to_string(x), sep=", "; return res+"}";
}

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

class Compare {
public:
	bool operator () (const PII& a, const PII& b) {
		return a.fi > b.fi || (a.fi == b.fi && a.se > b.se);
	}
};

int main() {
	// method 1, using class operator ()
	priority_queue<PII, vector<PII>, Compare> Q;

	// method 2, using lambda function, recommanded
	auto cmp = [&](int a, int b) {
		return a > b;
	};
	priority_queue<int, vector<int>, decltype(cmp)> > q(cmp);


	int n = 6;
	rep(i, 0, n) Q.push({i, n - i - 1});
	Q.push({0, 2});
	Q.push({0, 3});
	
	while(!Q.empty()) {
		auto v = Q.top();
		Q.pop();
		printf("(%d, %d)\n", v.fi, v.se);
	} 

	return 0;
}