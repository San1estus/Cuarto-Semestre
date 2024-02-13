#include <bits/stdc++.h>
using namespace std;
#define MAXN 50000
#define LOG_MAXN 16
#define isOn(S,j) (S& (1<<j))

int ST[MAXN][LOG_MAXN];
int parent[MAXN][LOG_MAXN]; 

int val[MAXN]; 
vector<int> listAdy[MAXN]; 
int depth[MAXN]; 
long long sumParents[MAXN]; 



void DFS(int currentNode, int prevNode){
	parent[currentNode][0] = prevNode;
	depth[currentNode] = (prevNode == -1) ? 0: depth[prevNode] + 1; 
	
	sumParents[currentNode] = val[currentNode];
	sumParents[currentNode] += (prevNode==-1)? 0: sumParents[prevNode];
	
    for(int n : listAdy[currentNode] ){
        if ( n != prevNode ){
            DFS(n, currentNode);
        }
    }
}

void sparseTableParent(int N) {
    for( int j = 1; (1 << j) <= N; j++ ){
        for( int nodo = 0; nodo < N; nodo++ ){
            if( parent[nodo][j-1] != -1 ){
                parent[nodo][j] = parent[parent[nodo][j-1]][j-1];
            }
        }
    }
}

void sparseTable(int N) {
    for( int j = 1; (1 << j) <= N; j++ ){
        for( int nodo = 0; nodo < N; nodo++ ){
            if(parent[nodo][j-1] != -1 && parent[nodo][j] != -1 ){
                	ST[nodo][j] = ST[nodo][j-1] + ST[parent[nodo][j-1]][j-1];
            }
        }
    }
}

long long query(int nodo, int d){
    long long sum = 0;
    if( d >=depth [nodo] ) 
		return sumParents[nodo];
   	if( d==0)  
		return val[nodo];
    d++;

    for( int i=31; i >= 0; i-- ){
        if( isOn(d,i) ) {
            sum += ST[nodo][i];
            nodo = parent[nodo][i];      
        }   
    }
    return sum;
}

void print(int N, int arr[MAXN][LOG_MAXN]){
	cout << endl;
	for( int i=0; i < N ; i++ ) {
		cout << i << ": ";
		for( int j=0; j < 5; j++ ){
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int N, Q, a, b;
    cin >> N >> Q;

    for(int i=0; i < N; i++){
        cin >> val[i];
        ST[i][0] = val[i];
    }

    for(int i=0; i<N-1; i++){
        cin >> a >> b;
        listAdy[a].push_back(b);
        listAdy[b].push_back(a);
    }

	for( int i=0; i < MAXN; i++ ){
		for( int j=0; j < LOG_MAXN ; j++ ){
			parent[i][j] = -1;
		}
	}
	
	DFS(0, -1);

	sparseTableParent(N);
    sparseTable(N);

    print(N, parent);
    print(N, ST);

    for( int i=0; i<N ; i++ ) {
    	cout << sumParents[i] << "  ";
    }cout << endl;

	for( int i=0; i<Q; i++) {
        cin >> a >> b;
        cout << query(a, b) << endl;
    }
	return 0;
}