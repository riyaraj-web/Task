class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) return false;
        stack<char> st;  // only need one stack
        
        for(int i = 0; i < s.size(); i++){
            // push opening brackets
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                // check if stack is empty (no matching opening bracket)
                if (st.empty()) return false;
                
                // check if closing bracket matches the most recent opening bracket
                if ((s[i] == ')' && st.top() == '(') ||
                    (s[i] == '}' && st.top() == '{') ||
                    (s[i] == ']' && st.top() == '[')) {
                    st.pop();  // valid pair, remove opening bracket
                } else {
                    return false;  // mismatch found
                }
            }
            // If character is not a bracket, we ignore it (or could return false)
        }
        
        return st.empty();  // valid only if all brackets are matched
    }
};