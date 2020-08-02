class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> ans;
        if(k == 0)
            return ans;
        if(shorter == longer){
            ans.push_back(shorter*k);
        }else{
            for(int i = 0; i <= k; i++){
                ans.push_back(longer*i + shorter*(k-i));
            }
        }
        return ans;
    }
};