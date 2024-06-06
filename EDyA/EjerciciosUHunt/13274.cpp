/*Para cada nodo verificamos que su cantidad de hijos sea K,
si la cantidad es menor no se puede que el subarbol tenga 
K nodos, por lo que solo nos quedamos con el mismo nodo, 
repetimos este proceso sobre los nodos hijos, de los hijos
nos interesa elegir aquellos con los subarboles mas 
grandes que satisfacen la propiedad buscada.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1002];

int dfs(int parent, int u, int k){
    int resp = 1, t = 0;

    if(adj[u].size() < k) return resp;

    vector<int> tamSubarboles;

    for(auto v : adj[u]){
        if(v == parent) continue;
        tamSubarboles.push_back(dfs(u, v, k));
    }

    if (tamSubarboles.size() < k)
        return 1;

    sort(tamSubarboles.rbegin(), tamSubarboles.rend());

    for (int i = 0; i < k; i++) {
        resp += tamSubarboles[i];
    }

    return resp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    int T, N, K, caso = 1;
    cin >> T;
    
    while(T--){
        cin >> N >> K;
        
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        
        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int resp = dfs(0, 1, K);
        
        cout << "Case " << caso++ << ": " << resp << endl;
    }
    
    return 0;
}
