class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();

        int mid = n/2;

        int i = 0, j = mid;

        int CountL = 0;
        int CountR = 0;

       unordered_set<char> st;
       st.insert('a');
       st.insert('e');
       st.insert('i');
       st.insert('o');
       st.insert('u');
       st.insert('A');
       st.insert('E');
       st.insert('I');
       st.insert('O');
       st.insert('U');

       while(i <n/2 && j<n) {
        if(st.find(s[i]) != st.end()) CountL++;

        if(st.find(s[j]) != st.end()) CountR++;

        i++;
        j++;
    }
    return CountL == CountR;

    }
};