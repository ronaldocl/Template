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
using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
const int M = 1e9 + 7;
/*-------------------------------*/

namespace Number {
	const int MAXN = 1000010;
	const int MAXP = 700000;
	int p[MAXP], fac[MAXN], phi[MAXN], pCnt, n;
	int e[MAXN], div[MAXN];
	bool h[MAXN];

	void init(int sz){
		n = sz;
	}

	void euler_seive(){
		pCnt = 0;
		rep(i, 1, n+1) fac[i] = i;
		rep(i, 2, n+1){
			if(fac[i] == i) { p[pCnt++] = i; phi[i] = i-1; e[i] = 1; div[i] = 2; }
			for(int j = 0, k; j < pCnt && (k = p[j]*i) <= n; ++j){
				fac[k] = p[j];
				if(i % p[j] == 0){
					phi[k] = phi[i] * p[j];
					div[k] = div[i] / (e[i]+1) * (e[i]+2);
					e[k] = e[i] + 1;
					break;
				}
				else{
					phi[k] = phi[i] * (p[j] - 1);
					div[k] = div[i] * div[p[j]];
					e[k] = 1;
				}
			}
		}
	}

	void eratosthenes_seive(){
		int m = int(sqrt(n + 0.5));
		memset(h, 0, sizeof(h));
		rep(i, 2, m+1){
			if(!h[i]) for(int j = i*i; j <= n; j += i) h[j] = 1;
		}
		pCnt = 0;
		rep(i, 2, n+1) if(!h[i]) p[pCnt++] = i;
	}

	vector<PII> factor(int x){
		vector<PII> res;
		while(x > 1){
			int y = fac[x], z = 0;
			while(x % y == 0) x /= y, z ++;
			res.push_back({y, z});
		}
		return res;
	}

	void phi_table(){
		rep(i, 2, n+1){
			if(fac[i] == i) phi[i] = i - 1;
			else{
				int x = i / fac[i]; 
				phi[i] = !(x % fac[i]) ? phi[x]*fac[i] : phi[x]*(fac[i] - 1);
			}	
		}	
	}

	template<typename T>
	T get_phi(T x){
		if(fac[x] == x) return x-1;
		int k = x / fac[x];
		return !(k % fac[x]) ? get_phi(k)*fac[x] : get_phi(k)*(fac[x]-1);
	}

	template<typename T>
	T gcd(T a, T b){
		return b ? gcd(b, a % b) : a;
	}

	template<typename T>
	T ex_gcd(T a, T b, T& d, T& x, T& y){
		if(b == 0) { d = a; x = 1; y = 0; }
		else { gcd(b, a%b, d, y, x); y -= x*(a/b); }
	}

	template<typename T>
	T pow_mod(T a, T b, T m){
		T res = 1, t = a;
		while(b){ if(b&1) res=res*t%m; t=t*t%m; b>>=1; }
		return res;
	}
}


int main(){

	Number::init(100000);
	Number::euler_seive();
	rep(i, 1, 30){
		printf("i = %d, phi = %d, e = %d, div = %d\n", i, Number::phi[i], Number::e[i], Number::div[i]);
	}
	

	return 0;
}