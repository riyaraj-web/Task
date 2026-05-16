class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();

        int l = 0;
        int r = n-1;

        int resultidx = 0;

        while (l <= r) {

            while (l < r && nums[l] == nums[l+1]) l++;
            while (r > l && nums[r] == nums[r-1]) r--;  // duplicate se bach jayenge 

            int mid = l + (r-l)/2;

            if(nums[mid] < nums[resultidx])
                resultidx = mid;

            if(nums[mid] > nums[r]) { //rotated
                l = mid+1;
            }else {
                r = mid-1;
            }
        }
        return nums[resultidx];
        
    }
};