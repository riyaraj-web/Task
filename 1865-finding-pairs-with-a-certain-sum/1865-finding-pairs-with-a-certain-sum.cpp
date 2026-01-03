class FindSumPairs {
    vector<int> nums1, nums2;
    unordered_map<int,int> freq2;

public:
    FindSumPairs(vector<int>& a, vector<int>& b) {
        nums1 = a;
        nums2 = b;
        for (int x : nums2)
            freq2[x]++;
        
    }
    
    void add(int index, int val) {
        int oldVal = nums2[index];
        freq2[oldVal]--;

        nums2[index] += val;
        freq2[nums2[index]]++;
        
    }
    
    int count(int tot) {
        int ans = 0;
        for (int x : nums1) {
            int need = tot - x;
            if (freq2.count(need))
                ans += freq2[need];
        }
        return ans;
    }
};

