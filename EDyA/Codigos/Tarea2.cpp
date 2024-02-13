#include <bits/stdc++.h>

using namespace std;

#define isOn(S,j) (S& (1<<j))

int val[50000]; 
vector<long long> listAdy[50000]; 
int depth[50000]; 

long long sumParents[50000]; 
long long ST[50000][16];
int parent[50000][16]; 

void DFS(int currentNode, int prevNode){
    sumParents[currentNode] = val[currentNode];
    sumParents[currentNode] += (prevNode==-1)? 0 : sumParents[prevNode];

    parent[currentNode][0] = prevNode;
    depth[currentNode] = (prevNode == -1) ? 0 : depth[prevNode] + 1; 
    
    for(int n : listAdy[currentNode]){
        if (n != prevNode){
            DFS(n, currentNode);
        }
    }
}

void sparseTableParents(int N) {
    for(int j = 1; (1 << j) <= N; j++){
        for(int node = 0; node < N; node++){
            if(parent[node][j-1] != -1){
                parent[node][j] = parent[parent[node][j-1]][j-1];
            }
        }
    }
}

void sparseTable(int N) {
    for(int j = 1; (1 << j) <= N; j++){
        for(int node = 0; node < N; node++){
            if(parent[node][j-1] != -1 && parent[node][j] != -1){
                    ST[node][j] = ST[node][j-1] + ST[parent[node][j-1]][j-1];
            }
        }
    }
}

long long query(int node, int d){
    long long sum = 0;
    if(d >= depth [node]) 
        return sumParents[node];
       if(d == 0)  
        return val[node];
    d++;

    for(int i = 31; i >= 0; i--){
        if(isOn(d,i)) {
            sum += ST[node][i];
            node = parent[node][i];      
        }   
    }
    return sum;
}

int main(void){
    int N, Q, l, r;
    cin >> N >> Q;

    for(int i = 0; i < N; i++){
        cin >> val[i];
        ST[i][0] = val[i];
    }

    for(int i = 0; i < N-1; i++){
        cin >> l >> r;
        listAdy[l].push_back(r);
        listAdy[r].push_back(l);
    }

    for(int i = 0; i < 50000; i++){
        for(int j = 0; j < 16 ; j++){
            parent[i][j] = -1;
        }
    }
    
    DFS(0, -1);

    sparseTableParents(N);
    sparseTable(N);


    for(int i=0; i<Q; i++) {
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}