class Solution {
public:
    bool equalSum(int idx, int target, vector<int>&nums, vector<vector<int>>&dp){
        
        if(idx == nums.size()) return false;
        if(target == nums[idx]) return true;
        if(dp[idx][target] != -1) return dp[idx][target];

        bool take = false;
        if(target - nums[idx] > 0){
            take = equalSum(idx+1, target-nums[idx], dp);
        }
        bool notTake = equalSum(idx+1, target, nums, dp);

        return dp[idx][target] = take || notTake;

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum%2 != 0) return false;
        int target = sum/2;
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return equalSum(0, target, nums, dp);
    }
};