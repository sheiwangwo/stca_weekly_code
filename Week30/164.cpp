class Solution {
public:
    // int maximumGap(vector<int>& nums) {
    //     int ans = 0;
    //     if(nums.empty())
    //         return ans;
    //     sort(nums.begin(), nums.end());
    //     for(int i = 0; i < nums.size()-1; i++){
    //         ans = max(ans, nums[i+1] - nums[i]);
    //     }
    //     return ans;
    // }
    struct Bucket{
        int minval;
        int maxval;
        bool used;
        Bucket(): minval(INT_MAX), maxval(INT_MIN), used(false){}
    };
    int maximumGap(vector<int>& nums){
        if(nums.size() < 2)
            return 0;
        int ans = 0;

        int maxE = *max_element(nums.begin(), nums.end());
        int minE = *min_element(nums.begin(), nums.end());
        int bucketSize = max(1, ((maxE - minE) / (int)(nums.size()-1)));
        int bucketNum = (maxE - minE) / bucketSize + 1;                         // number of buckets
        vector<Bucket> buckets(bucketNum);

        for (auto&& num : nums) {
            int bucketIdx = (num - minE) / bucketSize;                          // locating correct bucket
            buckets[bucketIdx].used = true;
            buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval);
            buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval);
        }

        int prevBucketMax = minE, maxGap = 0;
        for (auto&& bucket : buckets) {
            if (!bucket.used)
                continue;

            maxGap = max(maxGap, bucket.minval - prevBucketMax);
            prevBucketMax = bucket.maxval;
        }

        return maxGap;
    }
};