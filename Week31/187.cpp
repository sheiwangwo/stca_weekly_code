class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> ss;
        vector<string> ans;
        
        if(s.size() < 10)
            return ans;

        for(int i = 0; i <= s.size()-10; i++){
            string tmp = s.substr(i, 10);
            if(ss.find(tmp) != ss.end() && ss[tmp] == 1){
                ans.push_back(tmp);
            }
            ss[tmp]++;
        }

        return ans;
    }
};