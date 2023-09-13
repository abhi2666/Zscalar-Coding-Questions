#include <iostream>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int flag = 1;
        while(n > 0){
            // check if you can delete the elements
            int size = n;
            int i = 0; //1 - Ramos and -1 - zlatan
            while(i < n-1){
                if(s[i] != 'N' && s[i+1] != 'N' && s[i] != s[i+1]){
                    flag *= -1;
                    s[i] = s[i+1] = 'N';
                    size -= 2;
                    break;
                }
                i++;
            }
            if(size == n) break;
            else n = size;
            
        }
        if(flag == -1) cout<<"Zlatan"<<endl;
        else cout<<"Ramos"<<endl;
    }
	return 0;
}
