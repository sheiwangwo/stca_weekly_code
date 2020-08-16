class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty())
            return -1;
        int most = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            
            if(most == nums[i]){
                count++;
            }else{
                count--;
                if(count < 1){
                    most = nums[i];
                    count++;
                    continue;
                }
            }
            
        }
        return most;
    }
};