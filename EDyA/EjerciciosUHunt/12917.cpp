/*Si la cantidad de cazadores menos la cantidad de objetos es menor a 
la cantidad de jugadores, entonces es victoria, en caso contrario es
derrota.*/
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int H, P, O;
    while(cin >> P >> H >> O){
        if(P > O - H) cout << "Hunters win!" << endl;
        else cout << "Props win!" << endl;
    }

    return 0;
}