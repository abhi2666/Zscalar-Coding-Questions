class Solution {
public:
    int compareVersion(string version1, string version2) {
        string str1, str2;
        for(auto it : version1){
            if(it != '.' && it != '0') str1+=it;
        }
        for(auto it : version2){
            if(it != '.' && it != '0') str2+=it;
        }

        if(cnt1 > cnt2) return 1;
        else if(cnt1 < cnt2) return -1;
        else return 0;
    }
};