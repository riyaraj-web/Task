class Solution {
public:
    int removeDuplicates(vector<int>& nums) { //tc - 0(n) 
        int n = nums.size();                  //sc - 0(1)
        int start = 1;

        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                nums[start] = nums[i];
                start++;
            }
        }
        return start;
    }
};