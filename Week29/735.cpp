class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> mystack;
        vector<int> ans;
        for(auto as: asteroids){
            if(as > 0){
                mystack.push(as);
            }else{
                while(!mystack.empty() && -as >= mystack.top()){
                    if(mystack.top() == -as){
                        as = 0;
                    }
                    mystack.pop();
                }
                if(mystack.empty() && as != 0){
                    ans.push_back(as);
                }
            }
        }
        stack<int> tmpstack;
        while(!mystack.empty()){
            tmpstack.push(mystack.top());
            mystack.pop();
        }
        while(!tmpstack.empty()){
            ans.push_back(tmpstack.top());
            tmpstack.pop();
        }
        return ans;
    }
};