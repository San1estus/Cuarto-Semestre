/*Tenemos un arreglo de n x n, la entrada arr[i][j] representa la suma de areas
acumuladas que puede contener el rectangulo de area i x j, i la altura j el ancho
precalculamos esta area acumulada para todos los posibles recangulos.*/

#include <bits/stdc++.h>
#define MAXN 1001
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, q, h, w, hs, ws, hb, wb;
    cin >> t;
    while(t--){
        cin >> n >> q;
        vector<vector<long long>> areas(MAXN, vector<long long>(MAXN, 0));
        for(int i = 0; i < n; i++){
            cin >> h >> w;
            areas[h][w] += h*w;
        }
        
        for(int i = 1; i < MAXN; i++){
            for(int j = 1; j < MAXN; j++){
               areas[i][j] += areas[i-1][j] + areas[i][j-1] - areas[i-1][j-1]; 
            }
        }
        
        while(q--){
            cin >> hs >> ws >> hb >> wb;
            cout << areas[hb-1][wb-1] - areas[hb-1][ws] - areas[hs][wb-1] + areas[hs][ws]<< endl;
        }
    }
    return 0;
}
