/*Si 2 vectores estan sobre una misma linea, como trabajamos con enteros, entonces uno puede ser expresado
como multiplo del otro, si este es el caso, el vector mas cercano al origen siempre sera visible, mientras
que los otros solo seran visibles si tienen una altura mayor.*/
#include <bits/stdc++.h>
#define max(a,b) a < b ? b : a
using namespace std;

int gcd(int a, int b){
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    
    while(a){
		int temp = a;
		a = b%a;
		b = temp;
	}
	
	return b;
}

typedef struct luz{
    int x, y, z;
    bool operator<(const luz& a){
        return (long long)x*x + (long long)y*y < (long long)a.x*a.x + (long long)a.y*a.y;
    }
} p;

bool comp_luz(const luz& a, const luz& b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}


int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n, counter = 0;

    while(cin >> n, n){
        map<pair<int, int>, int> validos; 
        vector<luz> respuestas;
        vector<luz> luces(n);
        
        for(int i = 0; i < n; i++){
            cin >> luces[i].x >> luces[i].y >> luces[i].z;
        }
        sort(luces.begin(), luces.end());
        
        for(int i = 0; i < n; i++){
            int mult = gcd(luces[i].x,luces[i].y);
            pair<int,int> p(luces[i].x/mult,luces[i].y/mult);
            
            if(validos.count(p)){
               if(validos[p] >= luces[i].z) respuestas.push_back(luces[i]);
               validos[p] = max(validos[p], luces[i].z);
               
            } else validos[p] = luces[i].z;
        }
        sort(respuestas.begin(), respuestas.end(), comp_luz);
        cout << "Data set " << ++counter << ":" << endl;
        if(respuestas.empty()) cout << "All the lights are visible." << endl;
        else{
            cout << "Some lights are not visible:" << endl;
            for(int i = 0; i < respuestas.size(); i++){
                cout << "x = " << respuestas[i].x << ", y = " << respuestas[i].y;
                if(i + 1 < respuestas.size()) cout << ";" << endl;
                else cout << "." << endl;
            }
        }
    }

    return 0;
}