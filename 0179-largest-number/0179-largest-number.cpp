class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //convert integers to strings
        vector<string> array;
        for (int num : nums) {
            array.push_back(to_string(num));
        }
        //custom comparator for sorting
        sort(array.begin(), array.end(), [](const string &a, const string &b) {
            return (b + a) < (a + b);
        });

        //handle the case where the largest number is "0"
        if (array[0] == "0"){
            return "0";
        }

        //build the largest number from the sorted array
        string largest;
        for (const string &num : array){
            largest += num;
        }
        return largest;
        
    }
};