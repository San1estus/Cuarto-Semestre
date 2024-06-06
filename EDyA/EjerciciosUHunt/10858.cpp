/*Si un numero x divide a N obtenemos que x*N/x=N, entonces tenemos una posible factorizacion
de N, luego verificamos sobre estos factores obtenidos como pueden factorizar a N/x,
repetimos este proceso hasta llegar a raiz de N*/

#include <bits/stdc++.h>

using namespace std;

void factorizaciones(int n, int start, vector<int>& actual, vector<vector<int>>& resultados) {
    for (int i = start; i * i <= n; ++i) {
        if (n % i == 0) {
            actual.push_back(i);
            actual.push_back(n / i);
            resultados.push_back(actual);
            actual.pop_back();
            factorizaciones(n / i, i, actual, resultados);
            actual.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    vector<int> numeros;
    int n;
    
    while (cin >> n && n != 0) {
        numeros.push_back(n);
    }
    
    for (int number : numeros) {
        vector<vector<int>> resultados;
        vector<int> actual;
        
        factorizaciones(number, 2, actual, resultados);
        
        sort(resultados.begin(), resultados.end());
        
        cout << resultados.size() << endl;
        for (auto factorization : resultados) {
            for (int i = 0; i < factorization.size(); ++i) {
                if (i > 0) cout << " ";
                cout << factorization[i];
            }
            cout << endl;
        }
    }
    
    return 0;
}
