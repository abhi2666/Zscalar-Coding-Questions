/*
You are given a 0-indexed integer array nums. The array nums is beautiful if:

nums.length is even.
nums[i] != nums[i + 1] for all i % 2 == 0.
Note that an empty array is considered beautiful.

You can delete any number of elements from nums. When you delete an element, all the elements to the right of the deleted element will be shifted one unit to the left to fill the gap created and all the elements to the left of the deleted element will remain unchanged.

Return the minimum number of elements to delete from nums to make it beautiful.
*/

class Solution
{
public:
    int minDeletion(vector<int> &nums)
    {
        int flag = nums.size()%2? -1 : 1; // even length
        int count = 0;
        for (int i = 0; i < nums.size()-1; i++)
        {
            if((i-count)%2 == 0 && nums[i] == nums[i+1]){
                // make beautiful by deleting one element
                count++;
                flag *=-1;
            }
        }
        if(flag == -1) return count+1;
        else return count;
    }
};