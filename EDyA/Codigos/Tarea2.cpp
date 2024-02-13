#include <bits/stdc++.h>
using namespace std;
#define MAXN 50000
#define LOG_MAXN 16+2
#define isOn(S,j) (S& (1<<j))


int SP[MAXN][LOG_MAXN];
int Ancest[MAXN][LOG_MAXN]; 

int val[MAXN]; 
vector<int> listAdy[MAXN]; 
int profu[MAXN]; 
int sumTodosAnces[MAXN]; 



void DFS(int nodoAct, int nodoAnt){
	Ancest[nodoAct][0] = nodoAnt;
	profu[nodoAct] = (nodoAnt==-1)? 0: profu[nodoAnt] + 1; 
	
	sumTodosAnces[nodoAct] = val[nodoAct];
	sumTodosAnces[nodoAct] += (nodoAnt==-1)? 0: sumTodosAnces[nodoAnt];
	
    for( int n : listAdy[nodoAct] ){
        if ( n != nodoAnt ){
            DFS(n, nodoAct);
        }
    }
}

void sparseTableAncest(int N) {
    for( int j = 1; (1 << j) <= N; j++ ){
        for( int nodo = 0; nodo < N; nodo++ ){
            if( Ancest[nodo][j-1] != -1 ){
                Ancest[nodo][j] = Ancest[ Ancest[nodo][j-1] ][j-1];
            }
        }
    }
}

void sparseTable(int N) {
    for( int j = 1; (1 << j) <= N; j++ ){
        for( int nodo = 0; nodo < N; nodo++ ){
            if( Ancest[nodo][j-1] != -1 && Ancest[nodo][j]!=-1 ){
                	SP[nodo][j] = SP[nodo][j-1] + SP[ Ancest[nodo][j-1] ][j-1];
            }
        }
    }
}

int query(int nodo, int d){
    int sum = 0;
    if( d>=profu[nodo] ) 
		return sumTodosAnces[nodo];
   	if( d==0)  
		return val[nodo];
    d++;
    for( int i=31; i>= 0; i-- ){
        if( isOn(d,i) ) {
            sum += SP[nodo][i];
            nodo = Ancest[nodo][i];      
        }   
    }
    return sum;
}

void print(int N, int arr[MAXN][LOG_MAXN]){
	cout << '\n';
	for( int i=0; i<N ; i++ ) {
		cout << i << ": ";
		for( int j=0; j <5; j++ ){
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int N, Q, a, b;
    cin >> N >> Q;

    for(int i=0; i<N; i++){
        cin >> val[i];
        SP[i][0] = val[i];
    }
    for(int i=0; i<N-1; i++){
        cin >> a >> b;
        listAdy[a].push_back(b);
        listAdy[b].push_back(a);
    }

	for( int i=0; i<MAXN; i++ ){
		for( int j=0; j<LOG_MAXN ; j++ ){
			Ancest[i][j] = -1;
		}
	}
	
	DFS(0, -1);
	sparseTableAncest(N);
    sparseTable(N);

	for( int i=0; i<Q; i++) {
        cin >> a >> b;
        cout << query(a, b) << '\n';
    }
	return 0;
}