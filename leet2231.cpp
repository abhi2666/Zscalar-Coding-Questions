/*
You are given a positive integer num. You may swap any two digits
of num that have the same parity (i.e. both odd digits or both even digits).

Return the largest possible value of num after any number of swaps.

Input: num = 1234
Output: 3412
Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
*/

class Solution
{
public:
    int largestInteger(int num)
    {
        vector<int> even;
        vector<int> odd;
        string s = to_string(num);
        int temp = num;
        while (temp > 0)
        {
            int digit = temp % 10;
            if (digit % 2 == 0)
            {
                even.push_back(digit);
            }
            else
            {
                odd.push_back(digit);
            }
            temp = temp / 10;
        }

        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end(), greater<int>());
        int ans = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if((int)s[i] % 2 == 0){
                //even
                ans = ans*10 + even[i];
            }
            else{
                //odd
                ans = ans*10 + odd[i];
            }
        }
        
        return ans;
    }
};
