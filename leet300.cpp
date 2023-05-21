/*
Given an integer array nums, return the length of the longest strictly increasing 
subsequence.

Subsequence --> A subsequence is an array that can be derived 
from another array by deleting some or no elements without changing the 
order of the remaining elements.

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>vect;

        for(int i : nums){
            if(vect.size() == 0 || i > vect.back())
            {
                //add new element 
                vect.push_back(i);
            }
            else{
                // finding the smallest element in vector >= i
                auto it = lower_bound(vect.begin(), vect.end(), i);
                *it = i; //replacing the value by i
            }
        }

        return vect.size();
    }
};