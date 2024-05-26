/*Tercera edición*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; 
    double p;
    cout << fixed << setprecision(6);
    while(cin >> n >> p, n){
        double potencias[n + 1];
        potencias[0] = 1;
        
        for(int i = 1; i < n + 1; i++){
            potencias[i] = potencias[i-1]*p;
        }
        
        //dp[i][j] es la probabilidad de tener una racha de j o menos con i juegos.
        vector<vector<double>> dp(n+1, vector<double>(n+1, 1));
        
        for(int i = 1; i < n+1; i++){
            for(int j = 0; j < i; j++){
                /*
                 Si S representa nuestra racha de victorias tenemos que P(S<=j)=1-P(S>j), pero estamos acotados por i
                 si j=i-1, entonces P(S>j) = P(S=i), por lo tanto P(S<=j)=1-P(S=i).
                */
                if(j == i-1) dp[i][j] = 1-potencias[i];
                else{
                    
                    double previous = dp[i-j-2][j];
                    double winningStreak = potencias[j+1];

                    dp[i][j] = dp[i - 1][j] - previous*(1-p)*winningStreak;
                }
            }
        }
        
        double ans = 0;
        
        for(int i=1;i<=n;i++) ans += (dp[n][i]-dp[n][i-1])*i;
        cout << ans << endl;
    }
    
    return 0;
}