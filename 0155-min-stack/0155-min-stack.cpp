class MinStack {
public:
    stack<long long> st;
    long long min;
    
    MinStack() { // constructor
        min = LLONG_MAX;
    }
    
    void push(int val) { // O(1)
        long long x = (long long)val;
        if(st.size() == 0) {
            st.push(x);
            min = x;
        }
        else if(x >= min) {
            st.push(x);
        }
        else { // x < min
            st.push(2*x - min);  // Push encoded value
            min = x;             // Update min to current value
        }
    }
    
    void pop() { // O(1)
        if(st.empty()) return;  // Handle empty stack case
        
        if(st.top() < min) {    // Encoded value is present
            // Before popping, retrieve old min
            long long oldMin = 2*min - st.top();
            min = oldMin;
        }
        st.pop();
    }
    
    int top() { // O(1)
        if(st.empty()) return -1;  // Handle empty stack case
        
        if(st.top() < min) {
            return (int)min;       // Return actual minimum value
        }
        else {
            return (int)st.top();  // Return actual top value
        }
    }
    
    int getMin() { // O(1)
        if(st.empty()) return -1;  // Handle empty stack case
        return (int)min;
    }
};