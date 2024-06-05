#include <bits/stdc++.h>
using namespace std;

/*Comparamos los numeros de los distintos telefonos con el que recordamos
si la diferencia es menor a 1 lo imprimimos, en caso contrario no*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T, N, caso = 1;
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> T;
    while(T--){
        cin >> N;
        string telefonos[N];
        string telefonoMama;
        for(int i = 0; i < N; i++) cin >> telefonos[i];
        
        cin >> telefonoMama;
        
        cout << "Case " << caso++ << ":" << endl;
        
        for(int i = 0; i < N; i++){
            int diferencia = 0;
            for(int j = 0; j < telefonoMama.size(); j++){
                diferencia += telefonoMama[j] != telefonos[i][j];
            }
            if(diferencia <= 1)  cout <<  telefonos[i] << endl;
        }
        
    }
    
    return 0;
}