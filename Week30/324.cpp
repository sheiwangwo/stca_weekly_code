class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int numsSize = nums.size();
    int i, j;
    vector<int> ret(numsSize);
    sort(nums.begin(),nums.end(),greater<int>());
    for (i = 1, j = 0; i < numsSize; i++, j++) {
        ret[i++] = nums[j];
    }
    for (i = 0; i < numsSize; i++, j++) {
        ret[i++] = nums[j];
    }
    for (i = 0; i < numsSize; i++) {
        nums[i] = ret[i];
    }
        // sort(nums.begin(), nums.end());
        // vector<int> tmp = nums;

        // int size = tmp.size();
        // for(int i = 0; i < tmp.size(); i++){
        //     if(i < (tmp.size()+1) / 2){
        //         nums[i*2] = tmp[i];
        //     }else{
        //         if(tmp.size()%2==0){
        //             // i=i-1 i=i-3     
        //             // i=i-1 i=i-2
        //             nums[2*i-size+1] = tmp[i];
        //         }else{
        //             nums[2*i-size] = tmp[i];
        //         }
        //     }
        // }
    }
};