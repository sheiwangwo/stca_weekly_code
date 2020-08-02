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
    int ans;
    int LL, RR;
public:
    void sum(TreeNode* root){
        if(root){
            sum(root->left);
            sum(root->right);
            if(root->val < LL || root->val > RR){
                return;
            }else{
                ans += root->val;
            }
        }
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        ans = 0;
        LL = L, RR = R;
        sum(root);
        return ans;
    }
};