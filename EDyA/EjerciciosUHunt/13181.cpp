/*Cuarta edición*/

#include <bits/stdc++.h>
#define max(a,b) a < b ? b : a
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(cin >> s){
        int distMaxCamas = 0, ultimaCama = -1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'X'){
                if(ultimaCama == -1) distMaxCamas = max(distMaxCamas, i - 1), ultimaCama = i;
                else {
                    distMaxCamas = max((i - ultimaCama)/2 - 1, distMaxCamas), ultimaCama = i;
                }
            } 
        }
        if(ultimaCama != s.length()-1) distMaxCamas = max(distMaxCamas, s.length()-ultimaCama-2);
        cout << distMaxCamas << endl;
    }
    return 0;
}