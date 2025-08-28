class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        int smallest = INT_MAX;
        int secondsmallest = INT_MAX;

        for(int &num : nums){

            //track largest and second largest
            if(num > largest){
                secondLargest = largest;
                largest = num;
            } else {
                secondLargest = max(secondLargest, num);
            }

            //track smallest and secondsmallest
            if(num < smallest){
                secondSmallest = smallest;
                smallest = num;
            } else {
                secondSmallest = min(secondSmallest, num);
            }
        }
        return (largest * secondLargest) - (smallest * secondSmallest);
        
    }
};