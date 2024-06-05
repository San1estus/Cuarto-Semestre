/*Cuarta edición*/
#include <bits/stdc++.h>

using namespace std;
/*Los a_i solo toman valores entre 0 y 9, por lo tanto podemos hacer una dp
de i por 10, tal que dp[i][j] cuenta las repeticiones del numero j hasta la i-esima
posición y contamos estas repeticiones para la siguiente posición, el resultado sera la
cantidad de numeros tales que dp[r][j] > dp[l-1][j]*/

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    int n;
    while(cin >> n){
        int digito;
        vector<vector<int>> dp(n + 2, vector<int>(10, 0));
        
        for(int i = 1; i <= n; i++){
            cin >> digito;
            for(int j = 0; j < 10; j++) dp[i][j] = dp[i-1][j];
            dp[i][digito]++;
        }
        
        int q, l, r;
        cin >> q;
        
        while(q--){
            int resp = 0;
            cin >> l >> r;
            for(int i = 0; i < 10; i++) resp += dp[r][i] > dp[l-1][i];
            cout << resp << endl;
        }
        
    }
    return 0;
}
