#include <iostream>
using namespace std;

class Solution
{

public:
    int coinGame(int a[], int n)
    {
        int sum = 0, min_ele = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            sum += a[i];
            min_ele = min(min_ele, sum);
        }

        return abs(min_ele);
    }
};

int main()
{
    Solution s;
    int a[] = {2, -9, 15, -25, 10};
    // cout<<sizeof(a)<<" "<<sizeof(a[0])<<endl;
    int n = sizeof(a)/sizeof(a[0]);
    cout<<s.coinGame(a, n)<<endl;
    return 0;
}