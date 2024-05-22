/*De la tercera edición*/

#include <bits/stdc++.h>
#define max(a,b) a < b ? b : a
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, m;
    while(cin >> n && n) {
        int dp[101][101];
        int blocks[101][101];
        memset(dp, 0, sizeof(dp));
        memset(blocks, 0, sizeof(blocks));
        
        for(int i = 0; i < n; i++){
            cin >> l >> m;
            blocks[l][m]++;
        }
        
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j<= 100; j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] += blocks[i][j];
            }
        }
        cout << dp[100][100] << endl;
    }
    cout << '*' << endl;

    return 0;
}
