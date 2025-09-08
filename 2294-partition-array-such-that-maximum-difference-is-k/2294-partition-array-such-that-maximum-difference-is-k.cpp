class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int n = nums.size();

        int count = 1; //1st subsequence
        int minVal = nums[0]; //part of 1st subsequence

        for(int i = 0; i< n; i++){
            if(nums[i] - minVal > k){
                count++;
                minVal = nums[i];
            }
        }
        return count;
    }
};