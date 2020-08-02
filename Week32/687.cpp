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
    int ans;
    int arrowLength(TreeNode* root){
        if(!root)
            return 0;
        int leftlen = 0, rightlen = 0;
        int left = arrowLength(root->left);
        int right = arrowLength(root->right);

        if(root->left && root->left->val == root->val){
            leftlen = left+1;
        }
        if(root->right && root->right->val == root->val){
            rightlen = right + 1;
        }
        ans = max(ans, leftlen + rightlen);
        return max(leftlen, rightlen);
    }
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        arrowLength(root);

        return ans;
    }
};