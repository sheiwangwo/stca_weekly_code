class Solution {
public:
    // void sortColors(vector<int>& nums) {
    //     int n0 = 0;
    //     int n1 = 0;
    //     int n2 = 0;
    //     for(int i = 0; i < nums.size(); i++){
    //         if(nums[i] == 0){
    //             n0++;
    //         }
    //         else if(nums[i] == 1){
    //             n1++;
    //         }
    //         else{
    //             n2++;
    //         }
    //     }
    //     cout<<n0<<n1<<n2;

    //     for(int i = 0; i < nums.size(); i++){
    //         if(n0-- > 0){
    //             nums[i] = 0;
    //         }else if(n1-- > 0){
    //             nums[i] = 1;
    //         }else{
    //             nums[i] = 2;
    //         }
    //     }
    // }
void sortColors(vector<int>& nums) {
	int start = 0, end = nums.size() - 1;
	int pos = 0;
	
	while (pos <= end) {
		if (nums[pos] == 0) {
			swap(nums[pos++], nums[start++]);
		}
		else if (nums[pos] == 2) {
			swap(nums[pos], nums[end--]);
		}
		else {
			pos++;
		}
	}

}
};