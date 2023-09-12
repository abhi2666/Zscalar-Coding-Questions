/*
A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.
Example 2:

Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".

a - 3
b - 2
*/

class Solution {
public:
// aaabbbcc
 
    int minDeletions(string s) {
        unorderd_map<char, int>mp; // element and freq
        int cnt = 0;
        for(auto it : s){
            mp[it]++;
            if(mp.find(mp[it]) != mp.end()){
                cnt++;
                mp[it]--;
            }
        }

        return cnt;
    }
};

// CHATGPT
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp; // element and freq
        unordered_set<int> seenFreq; // to keep track of seen frequencies
        int cnt = 0;

        for (char it : s) {
            mp[it]++;
        }

        for (const auto &kv : mp) {
            int freq = kv.second;
            while (seenFreq.count(freq) > 0) {
                freq--;
                cnt++;
            }
            if (freq > 0) {
                seenFreq.insert(freq);
            }
        }

        return cnt;
    }
};
