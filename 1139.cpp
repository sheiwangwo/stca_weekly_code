class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int maxLen = 0;
        int height = grid.size();
        if(height == 0)
            return 0;
        int width = grid[0].size();

        vector<vector<vector<int>>> dp(height+1, vector<vector<int>>(width+1, vector<int>(2, 0)));

        for(int i = 1; i <= height; i++){
            for(int j = 1; j <= width; j++){
                if(grid[i-1][j-1] == 1){
                    dp[i][j][0] = dp[i][j-1][0]+1;
                    dp[i][j][1] = dp[i-1][j][1]+1;

                    int len = min(dp[i][j][0], dp[i][j][1]);
                    while(len > 0){
                        if(dp[i-len+1][j][0] >= len && dp[i][j-len+1][1]>= len){
                            maxLen = max(len, maxLen);
                            break;
                        }
                        len--;
                    }
                }
            }
        }
        return maxLen*maxLen;
    }
};