#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("cowsignal.in", "r", stdin);
    int M, N, K;

    cin >> M >> N >> K;

    char input[M][N];

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> input[i][j];
        }
    }
    
    freopen("cowsignal.out", "w", stdout);
    for(int i = 0; i < M*K; i++){
        for(int j = 0; j < N*K; j++){
            cout << input[i/K][j/K];
        }
        cout << endl;
    }

    return 0;
}