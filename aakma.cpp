/*
There are some groups of devils and they splitted into people to kill them. Devils make People to them left as their group and at last the group with maximum length will be killed. Two types of devils are there namely “@” and “$”
People is represented as a string “P”

Input string
PPPPPP@PPP@PP$PP

Output
7

Explanation
4 groups can be formed
PPPPPP@
PPP@
PP$
PP
*/

#include <iostream>
using namespace std;

class Solution
{

public:
    int deviGroup(string s)
    {
        int curr_count = 0, max_count = INT_MIN;
        for (auto c : s)
        {
            curr_count++;
            if (c == '@' || c == '$')
            {
                max_count = max(max_count, curr_count + 1);
                curr_count = 0;
            }
        }

        return max_count;
    }
};

int main()
{
    Solution s;
    cout << s.deviGroup("P@PP@PP$PP") << endl;
    return 0;
}