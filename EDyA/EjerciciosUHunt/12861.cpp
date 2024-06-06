/*Ordenamos las zonas horarias que se nos da, para cada valor
nos interesa comparar solamente sus valores adyacentes, digamos
para n compararlo con n-1 y n+1, pues cualquier valor mas lejano
que ese tendra una mayor diferencia. En el caso del último valor
lo comparamos con n-1 y 1. Al final imprimimos el mínimo entre 
los valores acumulados haciendo estas comparaciones.*/

#include <bits/stdc++.h>
using namespace std;

int diferenciaMinima(int a, int b){
    return min(abs(a-b), 24-abs(a-b));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    int n;
    while(cin >> n){
        int personas[n];
        for(int i = 0; i < n; i++) cin >> personas[i];
        sort(personas, personas+n);
        
        int comparandoIzq, comparandoDer;
        comparandoDer = comparandoIzq = 0;
        
        for(int i = 1; i < n-2; i+=2){
            comparandoIzq += diferenciaMinima(personas[i], personas[i-1]);
            comparandoDer += diferenciaMinima(personas[i], personas[i+1]);
        }
        
        comparandoDer += diferenciaMinima(personas[n-1], personas[0]);
        comparandoIzq += diferenciaMinima(personas[n-1], personas[n-2]);
        cout << min(comparandoIzq, comparandoDer) << endl;
    }
    return 0;
}
