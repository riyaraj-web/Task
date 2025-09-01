class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;

        int result = 0;

        for(string &word : words){
            string reverseWord = word;
            swap(reverseWord[0], reverseWord[1]);

            if(mp[reverseWord] > 0) {
                result += 4;
                mp[reverseWord]--;
            }else{
                mp[word]++;
            }
        }
        
        //check equal character word, use only one
        for(auto &it : mp){
            string word = it.first;
            int count = it.second;

            if(word[0] == word[1] && count > 0) {
                result += 2;
                break;
            }
        }
        return result;
    }
};