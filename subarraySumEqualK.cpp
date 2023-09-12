/*
Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

*/

class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {
        int n = arr.size(); // size of the given array.
        map<int, int> mpp;
        int preSum = 0, cnt = 0;

        mpp[0] = 1; // Setting 0 in the map.
        for (int i = 0; i < n; i++)
        {
            // add current element to prefix Sum:
            preSum += arr[i];

            // Calculate x-k:
            int remove = preSum - k;

            // Add the number of subarrays to be removed:
            cnt += mpp[remove];

            // Update the count of prefix sum
            // in the map.
            mpp[preSum] += 1;
        }
        return cnt;
    }
};