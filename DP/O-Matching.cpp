#include <bits/stdc++.h>
using namespace std;

int compatibles[21][21];
int dp[1 << 21];

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; i < N; j++){
            cin >> compatibles[i][j];
        }
    }

    dp[0] = 1;

    for (int k = 0; k < (1 << N); k++)
    {
        int parejas = __builtin_popcount(k);
        for(int m = 0; m < N; m++){
            if((k & (1 << m)) || !compatibles[parejas][m]) continue;

            dp[k | (1 << m)] += dp[k];
            dp[k | (1 << m)] %= (int)1e9 + 7;
        }
    }
    
    cout << dp[(1 << N)-1] << endl;

    return 0;
}