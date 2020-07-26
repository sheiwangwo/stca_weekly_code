class Solution {
public:
    int hammingDistance(int x, int y) {
        int yihuo = x^y;
        int ans = 0;
        while(yihuo){
            ans += yihuo & 1;
            yihuo = yihuo >> 1;
        }
        return ans;
    }
};