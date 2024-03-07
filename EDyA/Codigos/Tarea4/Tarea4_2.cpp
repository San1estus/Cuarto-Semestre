#include <bits/stdc++.h>
#define MAXN 50000
using namespace std;

vector<int> adj[MAXN]; 
vector<int> edges(MAXN); 

int vis[MAX]; 

int Euler[2 * MAX]; 

void add_edge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void eulerTree(int u, int &index)
{
	vis[u] = 1;
	Euler[index++] = u;
	for (auto it : adj[u]) {
		if (!vis[it]) {
			eulerTree(it, index);
			Euler[index++] = u;
		}
	}
}

int main()
{
	int N, Q, val1, val2;

	cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> val1;
        edges.push_back(val1);
    }

    for(int i = 0; i < N-1; i++){
        cin >> val1 >> val2;
        add_edge(val1, val2)
    }
    

	return 0;
}
