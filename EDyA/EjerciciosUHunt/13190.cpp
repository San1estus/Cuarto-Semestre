/*Cuarta edición*/
/*Utilizamos un conjunto para reestablecer las propiedades cambiando el tiempo de las medicinas
así no se tomara una medicina de manera consecutiva.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    int t, n, m;
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<string> medicina(3000);
        vector<int> minutos(3000);
        set<pair<int, int>> prioridades;
        for(int i = 0; i < n; i++){
            cin >> medicina[i] >> minutos[i];
            prioridades.insert({minutos[i], i});
        }
        
        for(int j = 0; j < m; j++){
            pair<int, int> temp = *prioridades.begin();
            prioridades.erase(temp);
            cout << temp.first << " " << medicina[temp.second] << endl;
            prioridades.insert({temp.first + minutos[temp.second], temp.second});
        }
    }
    return 0;
}