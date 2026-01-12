class Solution {
public:
    int findSumDivisors(int num){
        int divisors = 0; //count
        int sum = 0;   //sum of divisors

        for(int fact = 1; fact*fact <= num; fact++){
            if(num % fact == 0){
                int other = num/fact;

                if(other == fact) { //perfect square number
                    divisors += 1;
                    sum += fact;
                } else {
                    divisors += 2;
                    sum += (fact + other);
                }
            }

            if(divisors > 4)
                return 0; //invalid
        }
        return divisors == 4 ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for(int &num : nums){
            result += findSumDivisors(num);
        }
         
        return result;
    }
};