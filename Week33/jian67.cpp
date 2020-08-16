class Solution {
public:
    int strToInt(string str) {
        string num = "";
        bool pos = true;
        bool first = true;
        bool found = false;
        int ans = 0;
        for(auto c: str){
            if(c == ' ' && found == false){
                continue;
            }else{
                if((c == '+' || c == '-')&&first){
                    pos = c == '+';
                    first = false;
                    found = true;
                }
                else if(c >= '0' && c <= '9'){
                    num += c;
                    found = true;
                    first = false;
                }
                else{
                    break;
                }
            }
        }
        cout<<num;
        for(auto i: num){
            int w = i - '0';
            if(pos == false)
                w = 0 - w;
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && w >= 7)){
                ans = INT_MAX;
                break;
            }
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && w <= -8)){
                ans = INT_MIN;
                break;
            }

            ans = ans * 10 + w;
        }
        return ans;
    }
};