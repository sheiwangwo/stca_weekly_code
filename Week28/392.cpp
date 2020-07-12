class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lens = s.size(), lent = t.size();
        vector<vector<int>> dp(lens+1, vector<int>(lent+1));

        for(int i = 1; i < lens+1; i++){
            for(int j = 1; j < lent+1; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[lens][lent] == s.size();
    }
};