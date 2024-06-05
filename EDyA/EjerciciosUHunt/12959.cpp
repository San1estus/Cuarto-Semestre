#include <bits/stdc++.h>
using namespace std;

/*Simplemente comparamos las parejas por valor acumulado y en caso de empate se decide por el indice que le corresponde.*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, J, puntos;
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    while(cin >> J >> N){
        vector<pair<int,int>> nums(J, {0,0});
        pair <int, int> maximo = {0,0};
        while(N--){
            for(int i = 0; i < J; i++){
                cin >> puntos;
                nums[i % J].first += puntos;
                nums[i].second = i % J;
                maximo = max(maximo, nums[i % J]);
            }
        }
        cout << maximo.second + 1 << endl;
    }
    
    return 0;
}