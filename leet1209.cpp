/*
You are given a string s and an integer k, a k duplicate removal consists of choosing k 
adjacent and equal letters from s and removing them, causing the left and 
the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. 
It is guaranteed that the answer is unique.

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"

Approach --> we can use either stack, vector pair or map to store the charcter and its count
and once its count reaches k then we can simply remove that element from the stack.
*/
// vector.back() --> will return the element at the very back
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;

        for(auto c : s){
            //check if stack is empty or if current elements doesn't matches with the st.top ele
            if(st.size() == 0 || c != st.back()){
                //put into stack
                st.push_back({c, 1}); 
            }
            else{
                // if the element already exist in stack..inc. its count
                st.back().second++;
            }

            if(st.back().second == k){
                //means you can delete that element
                st.pop();
            }
        }
        string res;
        for(auto ch : st){
            res.append(ch.second, ch.first);
        }

        return res;
    }
};