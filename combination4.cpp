/*
Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
*/

class Solution {
public:
    int combiSum(vector<int>&nums, int n, int target, vector<int>&dp){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(dp[target]) return dp[target];
        int total = 0;
        for(int i = 0; i < n; i++){
            total += combiSum(nums, n, target-nums[i]);
        }

        return dp[target] = total;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums) sum += it;
        vector<int>dp(sum+1, -1);
        return combiSum(nums, n, target, dp);
    }
};

