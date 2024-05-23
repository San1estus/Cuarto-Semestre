/*Cuarta edición*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> lines(5);
    
    for (int i = 0; i < 5; ++i) {
        cin >> lines[i];
    }
    
    /*Podemos notar del patron dado al inicio que si el "bloque" del numero
    empieza con un ., entonces corresponde al 1, pues el 2 y el 3 no satifacen esto.
    Por otro lado, si en el cuarto renglon se inicia con un *, entonces corresponde
    al 2, pues el 2 y el 3 no satisfacen esto. Si no se encuentra nada de la forma anterior
    entonces el patron corresponde al 3. Además sabemos que los "bloques" de los numeros cambian
    cada 4 columnas, por lo cual podemos ir recorriendo el input de 4 en 4.*/
    
    for (int i = 0; i < 4*n; i += 4) {
        if(lines[0][i]=='.') cout << 1;
        else if(lines[3][i] == '*') cout << 2;
        else cout << 3;
    }

    cout << endl;

    return 0;
}
