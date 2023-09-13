class Solution
{
private:
    void restore(string temp, int idx, int segment, vector<string> &ans, string &s)
    {
        // we will accept the IP only if we have 4 segments and
        // we have traverse the whole string
        if (segment == 4 && idx >= s.size())
        {
            /// means we have travers the whole string and have got 4 segments
            temp.pop_back(); // will remove the last .
            ans.push_back(temp);
            return;
        }

        for (int i = 1; i <= 3 && i + idx <= s.size(); i++)
        {
            string str = s.substr(idx, i);
            // check for invalidity like a leading zero
            if (str[0] == '0' && str.size() > 1)
                return;
            else if (stoi(str) <= 255 && segment < 4)
            {
                // means its a valid number then move forward
                restore(temp + str + ".", idx + i, segment + 1, ans, s);
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        // we will keep track of how many segments have been formed
        // and also will track of current index
        restore("", 0, 0, ans, s);
        return ans;
    }
};