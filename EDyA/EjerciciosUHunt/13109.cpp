/*Ordenamos el arreglo y añadimos elefantes hasta que el peso
total sea mayor o igual al pesos que puede cargar la telaraña*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int t, m, w;
    cin >> t;
    while (t--) {
        cin >> m >> w;
        vector<int> elefantes(m);
        for(int i = 0; i < m; i++){
            cin >> elefantes[i];
        }
        
        sort(elefantes.begin(), elefantes.end());
        int resp, suma;
        resp = suma = 0;
        
        for(int i = 0; i < m; i++){
            if(suma + elefantes[i] > w) break;
            suma += elefantes[i];
            resp++;
        }
        
        cout << resp << endl;
    }

    return 0;
}
