/*Primero precalculamos la profundidad de cada nodo, calculamos el tamaño de cada subarbol formado
con una dfs y calculamos los ancestros de cada nodo. Luego cada query la procesamos para encontrar
el nodo que este a h niveles por arriba del nodo dado, si se encuentra un nodo valido, sabemos que
este sera unico por los datos del problema, entonces la respuesta sera 1, si no se encuentra ningun
nodo sera el mismo y la respuesta sera 0.*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_NODOS 100017
#define LOG 17

int n, parent[MAX_NODOS][LOG], depth[MAX_NODOS], countNodes[MAX_NODOS], subtreeSize[MAX_NODOS], answer[MAX_NODOS];
vector<int> tree[MAX_NODOS];
vector<pair<int,int>> queries[MAX_NODOS];

void calculateSubtreeSizes(int node=0) {
    subtreeSize[node] = 1;
    for(auto child : tree[node])
        calculateSubtreeSizes(child), subtreeSize[node] += subtreeSize[child];
}

void updateCount(int node, int increment=1) {
    countNodes[depth[node]] += increment;
    for(auto child : tree[node])
        if(child != -1) 
            updateCount(child, increment);
}

void dfs(int node=0, bool removeNodes=true) {
    updateCount(node); 
    for(auto query : queries[node])
        answer[query.second] = countNodes[query.first];
    
    int maxSubtreeSize = -1, mostSubordinate = -1;
    for(auto child : tree[node])
        if(subtreeSize[child] > maxSubtreeSize)
            maxSubtreeSize = subtreeSize[child], mostSubordinate = child;
    
    for(auto child : tree[node])
        if(child != mostSubordinate)
            dfs(child, false);
    
    if(maxSubtreeSize != -1)
        dfs(mostSubordinate);
    
    if(removeNodes)
        updateCount(node, -1); 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; 
    n++;
    
    for(int i = 1, p; i < n; i++) {
        cin >> p;
        tree[p].push_back(i);
        depth[i] = depth[parent[i][0] = p] + 1;
    }
    
    calculateSubtreeSizes();
    for(int v = 1; v < n; v++)
        for(int i = 1; i < LOG; i++)
            parent[v][i] = parent[parent[v][i - 1]][i - 1];
    
    
    int numQueries; 
    
    cin >> numQueries;
    
    for(int v, h, idx = 0; idx < numQueries; idx++) {
        cin >> v >> h;
        int node = v;
        for(int i = 0; i < LOG; i++)
            if((depth[v] - h - depth[node]) >> i & 1)
                node = parent[node][i];
        
        if(node)
            queries[node].push_back({depth[v], idx});
        else
            answer[idx] = 1; 
    }
    
    dfs();
    
    for(int i = 0; i < numQueries; i++)
        if(answer[i] - 1 != 0) cout << 1 << " ";
        else cout << 0 << " ";
    cout << '\n';
    
    return 0;
}
