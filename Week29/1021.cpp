class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans ="";
        vector<int> ansint;
        stack<int> si;
        for(int i = 0; i < S.size(); i++){
            if(S[i]=='('){
                si.push(i);
            }else if(S[i] == ')'){
                if(si.size()==1){
                    si.pop();
                }else{
                    ansint.push_back(si.top());
                    si.pop();
                    ansint.push_back(i);
                }
            }
        }
        sort(ansint.begin(), ansint.end());

        for(auto i: ansint){
            ans+=S[i];
        }
        return ans;
    }
};