class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxn = 0;
        vector<int> actnums(10001, 0);
        vector<int> dp(10001, 0);
        for(auto n: nums){
            actnums[n] += n;
            maxn = max(maxn, n);
        }

        dp[1] = actnums[1];
        dp[2] = max(actnums[1], actnums[2]);
        for(int i = 3; i<= maxn; i++){
            dp[i] = max(dp[i-2] + actnums[i], dp[i-1]);
        }
        return dp[maxn];
    }
};