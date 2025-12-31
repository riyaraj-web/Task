class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char &ch:s){
            //opening bracket
            if(ch== '(' || ch== '{' || ch== '[') {
                st.push(ch);
            }
            //closing bracket
            else {
                //stack is empty
                if(st.size()==0) return false;
                char tp = st.top();
                st.pop();

                if(ch == ']' && tp == '['){
                    continue;
                }
                else if(ch == '}' && tp == '{'){
                    continue;
                }
                else if(ch == ')' && tp == '('){
                    continue;
                }
                else{
                    return false;
                }
            }
        }

        if(st.empty())return true;
        return false;

    }
};