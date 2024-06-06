/*Conforme recibimos los resultados del i-esimo partido, vamos contando la racha de no victorias
si hay una victoria entonces se reinicia la racha, pero si en algun momento la racha se alcanzo
3 dejamos de contar los juegos en los que participo Rafa.*/
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int t, n, caso = 1;
    cin >> t;
    while(t--){
        
    bool flag = true;
        cin >> n;
        int cont = 0, juegos = 0;
        char c;
        for(int i = 0; i < n; i++){
            cin >> c;
            if(c == 'L' || c == 'D'){
                cont++;
                
                if(flag) juegos++;
                
                if(cont == 3) {
                 flag = false;
                 continue;
                }
            }
            else{
                if(cont < 3 && flag) juegos++;
                cont = 0;
            }
        }
        cout << "Case " << caso++ << ": ";
    
        if(!flag) cout << juegos;
        else cout << "Yay! Mighty Rafa persists!";
        
        cout << endl;
    }
    return 0;
}
