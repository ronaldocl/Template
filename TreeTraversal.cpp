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



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
//      5
//    /   \
//   3     7
//  / \   / \
// 2   4 6   8 
TreeNode* construct_tree() {
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node8 = new TreeNode(8);
	TreeNode* node3 = new TreeNode(3, node2, node4);
	TreeNode* node7 = new TreeNode(7, node6, node8);
	TreeNode* node5 = new TreeNode(5, node3, node7);

	return node5;
}


// tree level order traversal
void level_order(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()) {
		auto u = q.front();
		q.pop();
		cout << u->val << " ";
		if(u->left) q.push(u->left);
		if(u->right) q.push(u->right);
	}
}

int main() {
	TreeNode* root = construct_tree();

	level_order(root);
	

    return 0;
}



























