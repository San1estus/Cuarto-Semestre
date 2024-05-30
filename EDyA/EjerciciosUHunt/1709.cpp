/*Cuarta edición*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
	int p, a, b, c, d, n;
	while(cin >> p >> a >> b >> c >> d >> n){
	    double declinacion = 0;
	    double maximo = p * (sin(a + b) + cos(c + d) + 2);
	    for(int i = 2; i <= n; i++){
	        double actual = p * (sin(a * i + b) + cos(c * i + d) + 2);
	        if(maximo > actual){
	            if(declinacion < maximo - actual){
	                declinacion = maximo - actual;
	            }
	        } else maximo = actual;
	    }
	    cout << fixed << setprecision(9);
	    cout << declinacion << endl;
	}
}