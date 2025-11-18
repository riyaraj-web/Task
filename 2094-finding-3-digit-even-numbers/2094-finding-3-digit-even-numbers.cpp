class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        unordered_map<int, int> m; // Changed: declared the map
        
        for(int ele : arr){
            m[ele]++;
        }
        
        for(int i=100; i<=999; i+=2){
            int x = i;
            int a = x % 10; // ones place digit
            x /= 10;
            int b = x % 10; // tens place digit
            x /= 10;
            int c = x; // hundreds place digit
            
            // Create a temporary map to check availability
            unordered_map<int, int> temp = m;
            
            // Check if all three digits are available
            if(temp[a] > 0){
                temp[a]--;
                if(temp[b] > 0){
                    temp[b]--;
                    if(temp[c] > 0){
                        ans.push_back(i);
                    }
                }
            }
        }
        return ans;
    }
};