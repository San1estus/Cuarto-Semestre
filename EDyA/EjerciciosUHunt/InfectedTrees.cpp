/*Empezando desde la raiz nos interesa desconectar el subarbol profundidad, izquierdo, o r, derecho,
dependiendo cual tenga mas nodos, nos interesa repetir este proceso hasta llegar al fondo del
subarbol no desconectado y maximizar la cantidad de nodos restante, o equivalentemente
minimizar la cantidad de nodos desconctados.*/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 300010

vector<int> adj[MAXN];
int resp;

void dfs(int u, int parent, int profundidad){
    int tam = adj[u].size();
    
    if(u != 1) tam--; //No consideramos al padre
    if(tam <= 1) resp = min(resp, profundidad * 2 + 1 + tam);
    
    for(int i = 0; i < adj[u].size(); i++){
        if(adj[u][i] != parent) dfs(adj[u][i], u, profundidad + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i <= n; i++) adj[i].clear();
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        
        resp = INT_MAX;
        
        dfs(1,0,0);
        cout << n-resp << '\n';
    }
    
    
    
    return 0;
}
