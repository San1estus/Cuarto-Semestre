/*Rotamos la matriz matRecibida lo mas 4 veces, si las matrices son iguales
en alguna rotación entonces nos detenemos y determinamos que es 
posible. Si se completan las 4 rotaciones y no fue posible
determinamos que es imposible.*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    int matOriginal[2][2];
    int matRecibida[2][2];
    int t, caso = 1;
    cin >> t;
    while(t--){ 
        
        bool posible = true;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                cin >> matOriginal[i][j];
            }
        }
        
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                cin >> matRecibida[i][j];
            }
        }
        
        cout << "Case #" << caso++ << ": ";
        for(int r = 0; r < 4; r++){
            posible = true;
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    if(matRecibida[i][j] != matOriginal[i][j]){
                        posible = false;
                    }
                }
            }
            
            if(posible){
                cout << "POSSIBLE" << endl;
                break;
            }
            
            int temp = matRecibida[0][0];
            matRecibida[0][0] = matRecibida[1][0];
            matRecibida[1][0] = matRecibida[1][1];
            matRecibida[1][1] = matRecibida[0][1];
            matRecibida[0][1] = temp;
        }
        if(!posible){
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}
