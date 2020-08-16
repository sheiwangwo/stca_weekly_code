class Solution {
public:

    int find_another(int n){
        if( n % 2 == 0)
            return n+1;
        else
            return n-1;
    }
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        for(int i =0; i < row.size(); i = i+2){
            int p1 = row[i];
            int p2 = find_another(p1);
            if(row[i+1] != p2){
                int j = find(row.begin(), row.end(), p2) - row.begin();
                swap(row[i+1], row[j]);
                ans++;
            }
        }
        
        return ans;
    }
};