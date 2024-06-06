/*Iniciamos con 0 bloques de cada tipo de l y m, cada ve que se nos da un bloque
lo añadimos en el arreglo de bloques, como l y m son iguales podmeos apilar
la cantidad que haya de estos bloques en si mismos, entonces verificamos 
de los anteriores que bloques nos conviene mas apilar, los bloques con
l menor o con m menor*/

#include <bits/stdc++.h>
#define max(a,b) a < b ? b : a
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n, l, m;

    while(cin >> n, n) {
        vector<vector<int>> dp(101, vector<int>(101, 0));
        vector<vector<int>> bloques(101, vector<int>(101, 0));
        
        for(int i = 0; i < n; i++){
            cin >> l >> m;
            bloques[l][m]++;
        }
        
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j<= 100; j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] += bloques[i][j];
            }
        }
        cout << dp[100][100] << endl;
    }

    cout << '*' << endl;

    return 0;
}
