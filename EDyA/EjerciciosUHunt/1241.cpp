#include <bits/stdc++.h>
using namespace std;

/* 
Podemos ver las llaves del torneo como 0s y 1s:
1 si el participante está, 0 si no está. Si en una llave falta 1 de los participantes, 
hay un w/o (walkover), si faltan 2, habrá w/o en la siguiente ronda, por lo que se pone 
el valor correspondiente en la siguiente llave a 0. Además la siguiente ronda tendra 
la mitad de llaves, por lo que se reduce el tamaño a la mitad.
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("input.out", "w", stdout);
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        int tam = 1 << n; 
        
        bitset<1024> disponibles;
        disponibles.set();
        
        for (int i = 0; i < m; ++i) {
            int participante;
            cin >> participante;
            disponibles.set(participante - 1, false);
        }
        
        int walkOver = 0;
        
        while (tam > 1) {
            for (int i = 0; i < tam; i += 2) {
                if (disponibles[i]) {
                    if (!disponibles[i + 1])
                        ++walkOver;

                    disponibles.set(i >> 1, true);
                } else {
                    if (disponibles[i + 1]) {
                        ++walkOver;
                        disponibles.set(i >> 1, true);
                    } else {
                        disponibles.set(i >> 1, false);
                    }
                }
            }
            tam >>= 1;
        }
        
        cout << walkOver << "\n";
    }
    
    return 0;
}
