/*La idea del problema es encontrar el MST y el segundo MST*/

#include <bits/stdc++.h> 
using namespace std; 

vector<bool> valid, used;
vector<int> parent;
int N, M;

int find(int u)
{
    if(parent[u] == -1) return u;
    return parent[u] = find(parent[u]);
}

class Graph { 
    vector<vector<int>> edgelist; 
    int V;
public: 
    Graph(int V) {this ->V = V;} 
    
    void addEdge(int x, int y, int w) 
    { 
        edgelist.push_back({ w, x, y }); 
    } 

    int MST(bool first) 
    { 
        parent.assign(N+1, -1);
        int sets = N;
        sort(edgelist.begin(), edgelist.end()); 
        int resp = 0; 
        int cnt = 0;
        for (auto edge : edgelist) { 
            if(valid[cnt]){
                int w = edge[0]; 
                int x = edge[1]; 
                int y = edge[2]; 
                if (find(x) != find(y)) { 
                    if(first) used[cnt] = 1;
                    parent[find(x)] = find(y); 
                    resp += w;
                    sets--;
                }
            }
            cnt++;
        }
        if(sets == 1) return resp;
        return INT_MAX;
    } 
    
    int secondMST(){
        int resp = INT_MAX, tmp;
        for(int i = 0; i < M; i++){
            if(used[i]){
                valid[i] = 0;
                tmp = MST(0);
                if(tmp < resp)resp = tmp;
                valid[i] = 1;
            }
        }
        return resp;
    }
}; 

int main() 
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        used.clear();
        valid.clear();
        int u, v, w;
        cin >> N >> M;
        
        used.resize(M, 0);
        valid.resize(M, 1);
        
        Graph g(N);
        
        for(int i = 0; i < M; i++){
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        }
        
        int resp1 = g.MST(1);
        int resp2 = g.secondMST();

        cout << resp1 << " " << resp2 << endl;
    }

    return 0; 
}
