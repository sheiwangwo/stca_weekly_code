class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if (right == -1)
            return -1;
        while (left < right) {                                         
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[mid]) {                              
                if (nums[left] <= target && target <= nums[mid]) {     
                    right = mid;                                       
                } else {                                               
                    left = mid + 1;                                    
                }
            } else if (nums[left] > nums[mid]) {                       
                if (nums[mid] < target && target <= nums[right]) {     
                    left = mid + 1;                                    
                } else {                                               
                    right = mid;                                       
                }
            } else if (nums[left] == nums[mid]) {                      
                if (nums[left] != target) {                            
                    left++;
                } else {                                                
                    right = left;                                       
                }
            }
        }
        return (nums[left] == target) ? left : -1;                     
    }

};