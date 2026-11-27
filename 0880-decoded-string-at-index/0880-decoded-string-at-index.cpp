class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.length();
        long long size = 0;

        // Step 1: compute total decoded length
        for (char &ch : s) {
            if (isdigit(ch)) {
                size = size * (ch - '0');
            } else {
                size += 1;
            }
        }

        // Step 2: walk backwards, undoing each operation
        for (int i = n - 1; i >= 0; i--) {
            k = k % size;

            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }

            if (isalpha(s[i])) {
                size -= 1;
            } else {
                size /= (s[i] - '0');
            }
        }

        return "";
    }
};