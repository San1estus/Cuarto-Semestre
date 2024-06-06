/*Cuando un equipo verifica un problema sus entregas posteriores de ese problema no 
seran validas, entonces solo comparamos para cada problema las entregas validas
de equipos que no hayan obtenido aun ese problema, elegimos el que tenga el tiempo
de entrega mas tardio para cada problema.*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    int n, t, m, tiempo, equipo;
    cin >> n >> t >> m;
    char problema;
    string aceptado;
    
    vector<vector<bool>> marcador(t, vector<bool>(n, 1));
    vector<pair<int,int>> solProblemas(n, {-1, 0});
    
    while(m--){
        cin >> tiempo >> equipo >> problema >> aceptado;
        equipo--;
        if(aceptado == "Yes"){
            if(marcador[equipo][problema - 'A']){
                marcador[equipo][problema - 'A'] = 0;
                solProblemas[problema - 'A'] = {tiempo, equipo + 1};
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << char(i + 'A') << " ";
        if(solProblemas[i].first == -1) cout << "- -";
        else cout << solProblemas[i].first << " " << solProblemas[i].second;
        cout << endl;
    }
    return 0;
}
