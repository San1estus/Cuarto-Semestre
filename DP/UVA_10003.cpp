#include <bits/stdc++.h>
using namespace std;

int dp[52][52];

int cutRod(vector<int> prices, int n)
{
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else {
                if (i == 1) {
                    dp[i][j] = j * prices[i - 1];
                }
                else {
                    if (i > j) {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else {
                        dp[i][j] = max(prices[i - 1]
                                            + dp[i][j - i],
                                        dp[i - 1][j]);
                    }
                }
            }
        }
    }
 
    return dp[n][n];
}

int main (){
    
    memset(dp, -1, sizeof(dp));
    int l, n, cut;
    vector<int> cuts;
    
    while(true){
        cin >> l;
        if(l == 0) break;

        cin >> n;
        cuts.clear();
        cuts.push_back(0);

        for(int i = 0; i < n; i++){
            cin >> cut;
            cuts.push_back(cut);
        }
    }

    cout << "The minimum cutting is " << cutRod << "."; 
    return 0;
}