class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        for(int i = 0; i < nums.size(); i++)
        {
            int val = abs(nums[i]-target);
            if(mp.find(val) != mp.end()){
                return {i, mp[val]};
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return {-1};
    }
};