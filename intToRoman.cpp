/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.

Approach --> on notebook.. we will reduce the size of num given 
by first adding its corresponding char into res string.
*/

class Solution {
public:
    string intToRoman(int num) {
        string res;
        vector<pair<string, int>>mapp = {
            {"I", 1}, {"IV", 4}, {"V", 5},{"IX", 9}, {"X", 10},{"XL", 40}, {"L", 50},{"XC", 90}, {"C", 100},{"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000} 
        };

        int temp = num, i = 12;
        while(temp > 0 && i >= 0){
            // for 1400 -- 1400/1000 will be 1.4 which will be 1 
            // it shows the number of times we have to add that char into result
            int count = temp/mapp[i].second; 
            while(count--) res += mapp[i].first;
            // now 1400 has to be reduced to 400 by 1400 % 1000
            temp %= mapp[i].second;
            i--;
        }

        return res;
    }

};