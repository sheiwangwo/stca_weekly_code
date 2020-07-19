class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(),[](auto a, auto b){
            return a.size() > b.size() || (a.size() == b.size() && a < b);
        });

        vector<string> ans;
        for(auto ds: d){
            int i = 0;
            for(int j = 0; j < s.size(); j++){
                if(ds[i] == s[j])
                    i++;
            }
            if(i == ds.size())
                return ds;
        }
        return "";
    }
};