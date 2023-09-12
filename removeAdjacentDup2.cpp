/*
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"

repeatedly delete k adjacent items until whole string is parsed
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>>vect;
        string res;
        // we will put element on the stack and will also store their frequency
        for(auto ch : s)
        {
            // if vector is empty or if prev element does not match current 
            // element
            if(vect.size() == 0 || ch != vect.back().first)
            {
                vect.push_back({ch, 1});
            }
            else {
                // if prev matches the currrent element
                int newFreq = vect.back().second + 1;
                vect.push_back({ch, newFreq});
                if(vect.back().second == k){
                    // remove last k elements from vector
                    int temp = k;
                    while(temp--){
                        vect.pop_back();
                    }
                }
            }
        }
        // whatever char is left add them to a string and return it.
        for(auto it : vect){
            res += it.first;
        }

        return res;
    }
};