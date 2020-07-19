class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0;
        int anssum = 0;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        sort(nums.begin(), nums.end(), greater<int>());

        for(int i = 0; i < nums.size(); i++){
            ans.push_back(nums[i]);
            anssum += nums[i];
            sum -= nums[i];
            if(anssum > sum){
                break;
            }
        }
        return ans;
    }
};