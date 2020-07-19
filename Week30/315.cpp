class Solution {
public:
    // vector<int> countSmaller(vector<int>& nums) {
    //     // int len = nums.size();
    //     // if(len == 0)
    //     //     return vector<int>();
    //     // vector<int> ans(len);
    //     // ans[len-1] = 0;

    //     // for(int i = 1; i < len; i++){
    //     //     sort(nums.end()-i, nums.end());
    //     //     auto tmp = lower_bound(nums.end()-i, nums.end(), nums[len-1-i]);
    //     //     ans[len-1-i] = tmp - (nums.end()-i);
    //     // }
    //     // return ans;

    //     int len = nums.size();
    //     if(len == 0)
    //         return vector<int>();
    //     vector<int> ans(len);
    //     vector<int> sorted;
    //     for(int i = 0; i < len; i++){
    //         auto tmp = lower_bound(sorted.begin(), sorted.end(), nums[len-1-i]);
    //         int count = tmp - (sorted.begin());
    //         ans[len-1-i] = count;
    //         sorted.insert(tmp, nums[len-1-i]);
    //     }
    //     return ans;
    // }

struct Node {
	Node* left;
	Node* right;
	int val;
	int count = 0; // 左子树节点的个数
	Node(int val) : val(val), left(NULL), right(NULL) {}
};
Node* insert(Node* root, int val, vector<int>& res, int index) {
	if (!root) {
		//Node* tmp = new Node(val);
		return new Node(val);
	}
	if (val <= root->val) {
		root->count++;
		root->left = insert(root->left, val, res, index);
	}
	else {
		res[index] += root->count + 1;
		root->right = insert(root->right, val, res, index);
	}
	return root;
}
vector<int> countSmaller(vector<int>& nums) {
	Node* root = NULL;
	vector<int> res(nums.size());
	for (int i = nums.size() - 1; i >= 0; --i) {
		root = insert(root, nums[i], res, i);
	}
	return res;
}

};