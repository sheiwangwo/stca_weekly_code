class Solution {
public:
    bool divisorGame(int N) {
        // return !(N&1);

        vector<bool> dp(N+1, false);
        dp[2] = true;
        for(int i = 3; i <= N; i++){
            for(int j = 1; j < i/2; j++){
                if(i%j == 0 && dp[i-j] == false){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[N];
    }
};