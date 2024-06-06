/*Para que todos esten cantando la misma nota, la suma de sus
notas debe ser divisible por N, ya que en cada marca, el cambio
de las notas es 0 ya que una baja en 1 y otra aumenta en 1. Si 
se cumple que la suma es divisible entre N, la nota objetivo es
la del promedio. Para calcular la cadiad de marcas que se dan
calculamos el numero de cantantes que deben aumentar su nota
y los que la deben disminuir, nos interesa el maximo entre estas
2 cantidades.*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    while(cin >> n){
        vector<int> notas(n);
        long long suma = 0;
        for(int i = 0; i < n; i++){
            cin >> notas[i];
            suma += notas[i];
        }
        if(suma%n != 0) cout << -1 << endl;
        else{
            int meta = suma / n;
            int aumento = 0, decremento = 0;

            for (int nota : notas) {
                if (nota < meta) {
                    aumento += (meta - nota);
                } else if (nota > meta) {
                    decremento += (nota - meta);
                }
            }
            cout << max(aumento, decremento) + 1 << endl;
        }
    }
    
    return 0;
}
