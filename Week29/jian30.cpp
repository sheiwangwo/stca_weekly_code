class MinStack {
public:
    stack<int> data;
    stack<int> minS;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        data.push(x);

        if(minS.empty()){
            minS.push(x);
        }
        else if(minS.top() >= x){
                minS.push(x);
        }
    }
    
    void pop() {
        int tmp = data.top();
        data.pop();

        if(minS.top() == tmp)
            minS.pop();
    }
    
    int top() {
        if(data.empty())
            return -1;
        return data.top();
    }
    
    int min() {
        if(minS.empty())
            return -1;
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */