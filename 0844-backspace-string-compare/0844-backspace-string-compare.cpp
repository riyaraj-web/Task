class Solution {
public:
    string buildstring(string &s){
        string temp = "";
        int n = s.length();

        int i = 0;
        while(i < n){
            if(s[i] != '#')
                temp.push_back(s[i]);
        else if (temp.length()>0){
            temp.pop_back();
        }
        i++;
      }
      return temp;
    }
    bool backspaceCompare(string s, string t) {

        string buildFroms = buildstring(s);
        string buildFront = buildstring(t);

        return buildFroms == buildFront;
        
    }
};