 class Solution {
public:
    int calculate(string s) {
        long long result = 0, last = 0, num = 0;
        char op = '+';
        s += '+';
        
        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch != ' ') {
                if      (op == '+') { result += last; last =  num; }
                else if (op == '-') { result += last; last = -num; }
                else if (op == '*') { last *= num; }
                else if (op == '/') { last = (int)(last / (double)num); }
                op = ch;
                num = 0;
            }
        }
        return (int)(result + last);
    }
};