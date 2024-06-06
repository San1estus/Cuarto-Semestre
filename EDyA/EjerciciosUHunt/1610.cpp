/*Primero ordenamos los nombers en orden ascendente. Luego como tenemos una
cantidad par de nombres, solo ocupamos verificar el valor de n/2-1 ya que
es el mayor de la mitad inferior y el menor de la mitad superior, recorremos
hasta encontrar la primera discrepancia enter n/2-1 y n/2 y en esta posicion 
añadimos la letra con 1 valor mayor en orden lexicografico*/
#include <bits/stdc++.h>
#define min(a,b) a < b ? a : b

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int t;
    while(cin >> t, t){
        int it = 0;
        vector<string> nombres(t);
        for(int i = 0; i < t; i++){
            cin >> nombres[i];
        }
        
        sort(nombres.begin(), nombres.end());
        string respuesta;
        
        bool flag = true;
        while(flag){
            for(int i = nombres[t/2-1][it] - 'A'; i < 26; i++){
                respuesta = nombres[t/2-1].substr(0, it);
                respuesta += i + 'A';
                if(respuesta >= nombres[t/2-1] && respuesta < nombres[t/2]){
                  flag = false;
                  break;
                } 
            }
            it++;
            
        }
        cout << respuesta << endl;
    }
    
    return 0;
}
    