class Solution
{
public:
    int largestInteger(int num)
    {
        vector<int> odd, even, num1;
        while (num > 0)
        {
            int digit = num % 10;
            if (digit % 2 == 0)
            {
                even.push_back(digit);
                num1.push_back(digit);
            }
            else
            {
                odd.push_back(digit);
                num1.push_back(digit);
            }
            num /= 10;
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());
        int j = 0, k = 0;
        for (int i = 0; i < num1.size(); i++)
        {
            if (num1[i] % 2 == 0)
            {
                num1[i] = even[j];
                j++;
            }
            else
            {
                num1[i] = odd[k];
                k++;
            }
        }
        int res = 0;
        for (int i : num1)
        {
            res = res * 10 + i;
        }

        return res;
    }
};