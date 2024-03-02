#include <iostream>
#include <vector>
#define max(i, j) i < j ? j : i
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("speeding.in", "r", stdin);
    int M, N, len, mph, mile = 0, over_limit= 0;
    int road[100], bessie[100];
    
    cin >> M >> N;
    
    while(M--){
        cin >> len >> mph;
        while(len--){
            road[mile] = mph;
            mile++;
        }
    }
    mile = 0;

    while(N--){
        cin >> len >> mph;
        while(len--){
            bessie[mile] = mph;
            mile++;
        }
    }

    for(int i = 0; i < 100; i++){
        over_limit = max(over_limit, bessie[i]-road[i]);
    }

    freopen("speeding.out", "w", stdout);
    cout << over_limit << endl;
    return 0;
}