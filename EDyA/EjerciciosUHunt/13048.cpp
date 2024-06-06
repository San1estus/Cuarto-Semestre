/*Solo ocupamos verificar las condiciones dadas por el problema
para cada posicion de la calle.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int t;
    cin >> t;
    int caso = 1;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int resp = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != '-') continue;
            bool flag = true;
            
            if(s[i+1] == 'S' && i+1 < n) flag = false;
            if(s[i-1] == 'S' && i-1 >= 0) flag = false;
            if(s[i+1] == 'B' && i+1 < n) flag = false;
            if(s[i+2] == 'B' && i+2 < n) flag = false;
            
            if(flag) resp++;
        }
        cout << "Case " << caso++ << ": " << resp << endl;
    }
    return 0;
}