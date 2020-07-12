class Solution {
public:
    // bool count2Bigger(vector<int> nums, int index, int n) {
    //     int c = 0;
    //     for (int i = index; i < nums.size(); i++) {
    //         if (nums[i] > n) {
    //             c++;
    //             if (c >= 2)
    //                 return true;
    //         }
    //     }
    //     return false;
    // }

    // bool existBetweenN1N2(vector<int> nums, int index, int n1, int n2) {
    //     for (int i = index; i < nums.size(); i++) {
    //         if (nums[i] > n1&& nums[i] < n2) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // void dfs(vector<int> nums, int index, vector<int> tmp, vector<vector<int>>& ans) {
    //     if(ans.size() > 0)
    //         return;
    //     if (tmp.size() == 0) {
    //         for (int i = index; i < nums.size(); i++) {
    //             if (count2Bigger(nums, i, nums[i])) {
    //                 tmp.push_back(nums[i]);
    //                 dfs(nums, i + 1, tmp, ans);
    //                 tmp.pop_back();
    //             }

    //         }
    //     }
    //     else if (tmp.size() == 1) {
    //         for (int i = index; i < nums.size(); i++) {
    //             if (nums[i] > tmp[0]) {
    //                 if (existBetweenN1N2(nums, i, tmp[0], nums[i])) {
    //                     tmp.push_back(nums[i]);
    //                     // cut
    //                     dfs(nums, i + 1, tmp, ans);
    //                     tmp.pop_back();
    //                 }
    //             }
    //         }
    //     }
    //     else if (tmp.size() == 2) {
    //         for (int i = index; i < nums.size(); i++) {
    //             if (nums[i] < tmp[1] && nums[i] > tmp[0]) {
    //                 tmp.push_back(nums[i]);
    //                 ans.push_back(tmp);
    //                 tmp.pop_back();
    //             }
    //         }
    //     }

    // }
    // bool find132pattern(vector<int>& nums) {
    //     if(nums.size() < 3)
    //         return false;
    //     vector<vector<int>> ans;
    //     vector<int> tmp;
        
    //     dfs(nums, 0, tmp, ans);

    //     return !ans.empty();
    // }

    bool find132pattern(vector<int>& nums){
        if(nums.size() < 3)
            return false;
        stack<int> stack;
        vector<int> mins(nums.size());
        mins[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            mins[i] = min(mins[i - 1], nums[i]);
        for (int j = nums.size() - 1; j >= 0; j--) {
            if (nums[j] > mins[j]) {
                while (!stack.empty() && stack.top() <= mins[j])
                    stack.pop();
                if (!stack.empty() && stack.top() < nums[j])
                    return true;
                stack.push(nums[j]);
            }
        }
        return false;

    }
};