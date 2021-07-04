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

// merge sort, O(m + n)
int find_Kth_1(vector<int>& a, vector<int>& b, int k) {
	int m = a.size();
	int n = b.size();
	assert(k >= 1 && k <= m + n);

	int i = 0, j = 0;
	while(i < m && j < n) {
		if(a[i] <= b[j]) {
			i ++;
		}
		else {
			j ++;
		}
		if(i + j == k) break;
	}
	while(i < m && i + j < k) i ++;
	while(j < n && i + j < k) j ++;

	if(i == 0) return b[j - 1];
	if(j == 0) return a[i - 1];
	return max(a[i - 1], b[j - 1]);
}

// binary search, O(log(min(m, n)))
int find_Kth_2(vector<int>& a, vector<int>& b, int k) {
    if(a.size() > b.size()) {
        return find_Kth_2(b, a, k);
    } 

    int m = a.size();
    int n = b.size();
    assert(k >= 1 && k <= m + n);

    int l = max(0, k - n), r = min(m, k);
    while(l < r) {
        int i = l + (r - l) / 2;
        int j = k - i - 1;

        if(a[i] < b[j]) {
            l = i + 1;
        }
        else {
            r = i;
        }
    }

    int l1 = l, l2 = k - l;
    if(l1 == 0) return b[l2 - 1];
    if(l2 == 0) return a[l1 - 1];

    return max(a[l1 - 1], b[l2 - 1]);
}

// using find_Kth_2 with two pasess, 2 * O(log(min(m, n)))
double find_median_1(vector<int>& a, vector<int>& b) {
	int m = a.size();
	int n = b.size();
	if((m + n) & 1) {
		return find_Kth_1(a, b, (m + n) / 2 + 1);
	}
	else {
		return (find_Kth_1(a, b, (m + n) / 2) + find_Kth_1(a, b, (m + n) / 2 + 1)) / 2.0;
	}
}

// O(log(min(m, n)))
double find_median_2(vector<int>& a, vector<int>& b) {
	if(a.size() > b.size()) {
        return find_median_2(b, a);
    } 

    int m = a.size();
    int n = b.size();
   	int k = (m + n) / 2;

    int l = max(0, k - n), r = min(m, k);
    while(l < r) {
        int i = l + (r - l) / 2;
        int j = k - i - 1;

        if(a[i] < b[j]) {
            l = i + 1;
        }
        else {
            r = i;
        }
    }

    a.push_back(INF);
    b.push_back(INF);
    int l1 = l, l2 = k - l;
    int m1 = -1, m2 = -1;
    if(l1 == 0) {
    	m1 = b[l2 - 1];
    	m2 = min(a[0], b[l2]);
    }
    else if(l2 == 0) {
    	m1 = a[l1 - 1];
    	m2 = min(b[0], a[l1]);
    }
    else {
    	m1 = max(a[l1 - 1], b[l2 - 1]);
    	m2 = min(a[l1], b[l2]);
    }

    return (m + n) % 2 ? m2 : (m1 + m2) / 2.0;
}



int main(){
	int ok = 0;
	for(int i = 0; i < 10000; ++i) {
		int m = rand() % 100 + 1;
		int n = rand() % 100 + 1;

	    vector<int> a(m, 0), b(n, 0);
	    for(int j = 0; j < m; ++j) {
	    	a[j] = rand() % 10000;
	    }
	    for(int j = 0; j < n; ++j) {
	    	b[j] = rand() % 10000;
	    }

	    sort(a.begin(), a.end());
	    sort(b.begin(), b.end());

	    vector<int> c(a);
	    c.insert(c.end(), b.begin(), b.end());
	    sort(c.begin(), c.end());

	    int k = (m + n) / 2;
	    int median = (m + n) % 2 ? c[k] : (c[k - 1] + c[k]) / 2.0;

	    int median1 = find_median_1(a, b); 
	    int median2 = find_median_2(a, b);

	    if(median == median1 && median == median2) ok ++;
	}

	cout << "ok = " << ok << endl;


    return 0;
}