class MyQueue {
public:

    stack<int> input;
    stack<int> output;
    int peekEl = -1;

    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()){
            peekEl = x;
        }
        input.push(x); //ye to har baar karna hai
         
    }
    //amortized 0(1)
    int pop() {
        if(output.empty()) {
            //input -> output 0(n)
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        int val = output.top(); //0(1)
        output.pop();
        return val;
        
    }
    
    int peek() {
        if(output.empty())
            return peekEl;
        return output.top();
    }
    
    bool empty() {
        if(input.empty() && output.empty())
            return true;
        
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */