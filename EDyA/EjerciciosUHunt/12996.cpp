#include <bits/stdc++.h>
using namespace std;

/*Comparamos la maxima cantidad que se puede tener con la cantidad real de cada mango 
si se satisface eso verificamos que la suma de las cantidades reales de los mangos
sea menor al maximo de mangos por dias*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T, N, L, caso = 1;
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> T;
    while(T--){
        bool posible = true;
        cin >> N >> L;
        
        int cant_tipos[N];
        int cant_posibles[N];
        
        int suma = 0;
        
        for(int i = 0; i < N; i++) cin >> cant_tipos[i];
        for(int i = 0; i < N; i++) cin >> cant_posibles[i];
        
        for(int i = 0; i < N; i++){
            if(cant_tipos[i] > cant_posibles[i]){
                posible = false;
                break;
            }
            suma += cant_tipos[i];
        }
        
        
        cout << "Case " <<caso++ << ": ";
        
        if(posible && suma <= L) cout << "Yes";
        else cout << "No";
        
        cout << endl;
    }
    
    return 0;
}