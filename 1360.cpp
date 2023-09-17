class Solution
{
private:
    vector<int>md = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool leapYear(int year)
    {
        if((year%4 == 0 && !year%100==0) || year%400 == 0){
            return true;
        } 
        return false;
    }

    int getDays(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int days = stoi(date.substr(8, 2));

    int ans = 0;
    
    for (int i = 1; i < year; i++) {
        ans += leapYear(i) ? 366 : 365;
    }

    for (int i = 0; i < month - 1; i++) {
        ans += md[i];
    }

    if (leapYear(year) && month > 2) {
        ans += 1;
    }

    ans += days;

    return ans;
}


public:
    int daysBetweenDates(string date1, string date2)
    {
        int d1 = getDays(date1);
        int d2 = getDays(date2);
        int year1 = date1.substr(0, 4);
        int year2 = date2.substr(0, 4);
        if(year1 > year2){
            d1 += 365;
        }
        else if(year2 > year1){
            d2 += 365;
        }
        return abs(d1-d2);
    }
};