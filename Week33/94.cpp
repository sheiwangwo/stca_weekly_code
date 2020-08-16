/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
struct node {
	bool visited;
	TreeNode* n;
	node(bool v, TreeNode* n) : visited(v), n(n) {}
};
vector<int> inorderTraversal(TreeNode* root) {
	//WHITE, GRAY = 0, 1
	vector<int> ans;
	stack<node> ns;
	ns.push(node(0, root));
	while (!ns.empty()) {
			node tmp = ns.top();
			ns.pop();
			if (tmp.n == NULL)
				continue;
			if (tmp.visited == 0) {
				ns.push(node(0, tmp.n->right));
				ns.push((node(1, tmp.n)));
				ns.push((node(0, tmp.n->left)));
			}
			else {
				ans.push_back(tmp.n->val);
			}
		}
	return ans;

}
};