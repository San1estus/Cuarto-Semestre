/*Contamos las combinaciones posibles que seran a*b*c*d*d*e*e
se multiplica 2 veces por d y por e ya que son pares de calcetas
y pares de zapatos.*/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 300010


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    long long a,b,c,d,e;
    while(cin >> a >> b >> c >> d >> e && a){
        cout << a*b*c*d*d*e*e << endl;
    }
    
    
    return 0;
}
