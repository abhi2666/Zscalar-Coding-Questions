class Solution {
public:

    bool getWinner(int i, int j, int k, vector<int>&nums){
        if(i > j) return 0;

        int pickFirst = 0, pickLast = 0, ans = 0;
        if(k%2 == 0)
        {
            // player 1 turn 
            pickFirst = nums[i]+getWinner(i+1, j, k+1, nums);
            pickLast = nums[j] + getWinner(i, j-1, k+1, nums);
            ans = max(pickFirst, pickLast); // will maximize the answer 
        }
        else
        {
            // player 2 turn
            pickFirst -= nums[i] + getWinner(i+1, j, k+1, nums);
            pickLast -= nums[j] + getWinner(i, j-1, k+1, nums);
            ans = min(pickFirst, pickLast);
        
        }
        return ans;
    }

    bool predictTheWinner(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        return getWinner(i, j, 1, nums) >= 0;
    }
};