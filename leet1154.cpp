/*
Given a string date representing a Gregorian calendar
date formatted as YYYY-MM-DD, return the day number of the year.

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.

Input: date = "2019-02-10"
Output: 41
*/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isLeapYear(int year)
    {
        if (year % 4 == 0)
        {
            if (year % 100 != 0)
                return true;
            if (year % 400 == 0)
                return true;
        }
        return false;
    }

    int dayOfYear(string date)
    {
        int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = stoi(date.substr(0, 4));
        int months = stoi(date.substr(5, 2));
        int days = stoi(date.substr(8, 2));
        // cout<<days<<endl;
        int totalDays = 0;
        totalDays += days;
        // cout<<totalDays<<endl;
        for (int i = 0; i < months - 1; i++)
        {
            totalDays += daysInMonths[i];
        }
        if (months > 2)
        {
            // now check for leap year..
            if (isLeapYear(year))
            {
                return totalDays + 1;
            }
            else
            {
                return totalDays;
            }
        }
        return totalDays;
    }
};

int main()
{
    Solution s;
    cout << s.dayOfYear("2019-02-10") << endl;
    return 0;
}