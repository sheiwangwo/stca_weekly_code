class Solution {
public:
    int waysToStep(int n) {
        vector<int> dp(n+3);
        int m = 1000000007;
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 4;
        for(int i = 3; i < n; i ++){
            dp[i] = ((dp[i-1] % m + dp[i-2] % m) % m + dp[i-3] % m) %m; 
                 // ((dp[i-1] % m + dp[i-2] % m) % m + dp[i-3] % m)%m;
        }
        return dp[n-1];
    }
};