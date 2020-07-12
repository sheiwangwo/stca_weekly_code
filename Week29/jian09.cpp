class CQueue {
    stack<int> s1;
    stack<int> s2;
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        if(!s2.empty()){
            int ans = s2.top();
            s2.pop();
            return ans;
        }

        return -1;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */