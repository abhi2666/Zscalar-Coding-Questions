/*
Count the no. of ones in their bit form and sort then based on that.
can be done with %2 and /2 operations for each number.
*/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        vector<pair<int,int>> v;
        for (auto val: arr){
            int dem= val;
            int cnt=0;
            while (dem>0){
                cnt+= (dem&1);
                dem= dem>>1;
            }
            v.push_back({cnt,val});
        }
        sort(v.begin(),v.end());
        for (auto val: v)ans.push_back(val.second);
        return ans;
    }
};