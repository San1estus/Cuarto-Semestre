#include <bits/stdc++.h>
using namespace std;

/*Iteramos de 1 hasta la raiz cuadrada de N, pues los divisores vienen por
pares ya que si n divide a N, entonces N/n también, si un numero es divisor
de N verificamos que no sea multiplo de K, si es el caso lo añadimos a la
suma en caso contrario lo saltamos*/


void respuesta(int N, int K) {
    long long sum = 0;
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            if (i % K != 0) {
                sum += i;
            }
            if (i != N / i && (N / i) % K != 0) {
                sum += N / i;
            }
        }
    }
    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T, N, K;
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> T;
    while(T--){
        cin >> N >> K;
        respuesta(N, K);
    }
    
    return 0;
}