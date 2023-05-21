/*
Given an array of integers nums, you start with an initial 
positive value startValue.

In each iteration, you calculate the step by step sum of 
startValue plus elements in nums (from left to right).

Return the minimum positive value of startValue such that 
the step by step sum is never less than 1.

 Input: nums = [-3,2,-3,4,2]
Output: 5
Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
step by step sum
startValue = 4 | startValue = 5 | nums
  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
  (4 +2 ) = 6  | (5 +2 ) = 7    |   2

Approach -->
we simply have to find a number that when added with the elements, never gives 
a value < 1 in each step.

We will just find the prefix sum (adding one element to the next and soon) and
will the find the smallest sum possibly we can get..then we will just the return 
a positive value greater than it by 1. 

ex --> for -4 we can return 5 
*/
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mini = INT_MAX;
        int prefixSum = 0;
        for(int i : nums){
            prefixSum += i;
            mini = min(prefixSum, mini);
        }
        return mini > 0 ? 1 : abs(mini)+1;
        
    }
};