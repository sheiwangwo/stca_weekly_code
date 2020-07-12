class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> mystack;
        int id, t, pre = 0;
        for(auto log: logs){
            bool istart = log.find("start") != -1;
            sscanf(log.c_str(), istart ? "%d:start:%d" : "%d:end:%d", &id, &t);
            
            if(!mystack.empty()){
                int preid = mystack.top();
                ans[preid] += t - pre + (!istart);

                if(!istart && preid == id)
                    mystack.pop();
            }
            if(istart)
                mystack.push(id);

            pre = istart ? t:t+1;
        }
        return ans;
    }
};