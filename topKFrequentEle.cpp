/*
we have to delete the top k elements with the highest frequencies.
and for that what we can do is we can first create a map to store 
element and their freq and then we can put it into a min heap priority queue
and then remove all the elements with lesser freq from the pq until only k 
elements are left.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp; // ele and freq
        for(int ele : nums){
            mp[ele]++;
        }
        // now we will store freq and ele in pq and by default pq will arrange
        // elements based on the first value and the type of pq it is.
        // for this question we will use min heap because then only we will be 
        // able to remove min freq elements first.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto it : mp)
        {
            pq.push({it.second, it.first});
            if(pq.size() > k) pq.pop();
        }
        // now just add those element into a vector
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};