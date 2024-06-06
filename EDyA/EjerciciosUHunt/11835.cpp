/*En cada grand prix sumamos la puntuacion acorde a lo que se nos da
al final escogemos al/los que tengan la mayor puntuacion y los imprimimos*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    int g, p, s, pos, k, puntuacion;
    while(cin >> g >> p, g){
        
        vector<vector<int>> llegadas(g, vector<int>(p + 1));
        
        for(int i = 0; i < g; i++){
            for(int j = 1; j <= p; j++){
                cin >> pos;
                llegadas[i][pos] = j;
            }
        }
        
        cin >> s;
        
        for(int i = 0; i < s; i++){
            cin >> k;
            vector<int> puntuaciones(p + 1, 0);
            for(int j = 1; j <= k; j++){
                cin >> puntuacion;
                for(int m = 0; m < g; m++){
                    int piloto = llegadas[m][j];
                    puntuaciones[piloto] += puntuacion;
                }
            }
            
            int cantGanadores = 1;
            int ganadores[p] = {};
            ganadores[0] = 0;
            
            for(int j = 1; j <= p; j++){
                if(puntuaciones[j] > puntuaciones[ganadores[0]]){
                    cantGanadores = 0;
                    ganadores[cantGanadores] = j;
                    cantGanadores++;
                }
                else if(puntuaciones[j] == puntuaciones[ganadores[0]]){
                    ganadores[cantGanadores] = j;
                    cantGanadores++;
                }
            }
            
            for(int j = 0; j < cantGanadores; j++){
                if(j) cout << ' ';
                cout << ganadores[j];
            }
            cout << endl;
        }
    }
    return 0;
}
