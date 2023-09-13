// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         int size1 = s1.size(), size2 = s2.size(), s3 = s3.size();
//         if(s1.empty() && s2.empty()) return true;
//         if(size1 + size2 != size3) return false;

//         int i = 0, j = 0, k = 0;
//         while(i < size1 && j < size2){
//             if(s3[k] == s1[i]){
//                 i++;
//                 k++;
//             }
//             else if(s3[k] == s2[j]){
//                 j++;
//                 k++;
//             }
//             else{
//                 // does not match with anything
//                 return false;
//             }
//         }

//         while(i < size1){
//             if(s1[i] == s3[k]){
//                 i++;
//                 k++;
//             }
//             else {
//                 return false;
//             }
//         }

//         while(j < size2){
//             if(s2[j] == s3[k]){
//                 j++;
//                 k++;
//             }
//             else return false;
//         }

//         return true;
        
//     }
// };

// DP solution
class Solution {
public:

    bool checkInterleave(int i, int j, int k, string&s1, string&s2, string&s3, vector<vector<int>>&dp){
        
        if(i == s1.size() && j == s2.size() && k == s3.size()) return true;

        // will check if we can pick the current k element from s1 or s2 or both
        if(dp[i][j] != -1) return dp[i][j];
        bool first = false, second = false;
        if(i < s1.size()){
            if(s1[i] == s3[k]){
                first = checkInterleave(i+1, j, k+1, s1, s2, s3, dp);
            }
        }
        if(j < s2.size()){
            if(s2[j] == s3[k]){
                second = checkInterleave(i, j+1, k+1, s1, s2, s3, dp);
            }
        }
        
        return dp[i][j] = first || second; // because I want true only if possible

    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>>dp(s1.size()+1, vector<int>dp(s2.size()+1, -1));
        return checkInterleave(0, 0, 0, s1, s2, s3, dp);
        
    }
};