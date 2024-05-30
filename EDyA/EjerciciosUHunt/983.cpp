/*Cuarta edición*/
#include <iostream>
using namespace std;

/*dp[i][j] es la sma de los rectangulos de (1,1) hasta (i,j)
como puede haber traslapes a la hora de la suma se restan 
estos elementos duplicados.*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n, m;
    bool siguiente = false;
    while(cin >> n >> m){
        int dp[1002][1002];
        for(int i = 0; i < n; i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> dp[i][j];
                dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        if(siguiente) cout << endl;
        siguiente = true;
        int suma = 0;
        int k = n - m + 1;
        for(int i = 1; i <= k; i++){
            for(int j = 1; j<= k; j++){
                int escalar = dp[i+m-1][j+m-1] - dp[i-1][j+m-1] - dp[i + m-1][j-1] + dp[i-1][j-1];
                cout << escalar << endl;
                suma += escalar;
            }
        }
        cout << suma << endl;
        
    }
    return 0;
}
