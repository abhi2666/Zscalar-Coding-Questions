/*
Two Sum

Approach -->
1. Map 
2. Binary Search (after sorting)
3. Recursion (backtracking)
*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
       unordered_map<int, int> mp; // element and index
       for(int i = 0; i < nums.size(); i++){
        //check if {target - this element} is there in map or not
        if(mp.find(target-nums[i]) != mp.end()){
            return {mp[target-nums[i]], i};
        }
        else{
            // if that element does not exist then you can add it into map
            mp[target-nums[i]] = i;
        }
       }

       return {-1, -1}; // way of returning a vector of size 2

    }
};