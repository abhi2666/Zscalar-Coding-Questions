#include <iostream>
#include <vector>
using namespace std;


class Solution{

public:

    int minSwaps(int a[], int n)
    {
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 0)
            {
                int j = i;
                while(j--)
                {
                    if(a[j] == 1){count++;}
                }
            }
        }

        return count;
    } 

};

int main() {
    Solution obj;
    int a[] = {0, 1, 0, 1, 1, 0};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<obj.minSwaps(a, n)<<endl;

    return 0;
}
