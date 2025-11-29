class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> uniqueQuads;
        
        for(int i = 0; i < n-3; i++) {
            for(int j = i+1; j < n-2; j++) {
                unordered_set<long long> hashSet;
                for(int k = j+1; k < n; k++) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long fourth = target - sum;
                    
                    if(hashSet.find(fourth) != hashSet.end()) {
                        vector<int> quad = {nums[i], nums[j], (int)fourth, nums[k]};
                        sort(quad.begin(), quad.end());
                        uniqueQuads.insert(quad);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }
        
        return vector<vector<int>>(uniqueQuads.begin(), uniqueQuads.end());
    }
};