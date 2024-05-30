/*Tercera edición*/

/*
Nos interesa 3 numeros tales que a*b*c=a+b+c, notemos que
a*b*c=a+b+c => c(a*b-1)=a+b
            => c=a+b/(a*b-1),
mientras b no sea igual a 1/a. Nos interesa trabajar con enteros positivo,
entonces podemos tomar lo anterior como
a*b*c=(a+b+c)10000 => c(a*b-10000)=(a+b)10000
                   => c=10000(a+b)/(a*b-10000),
esto mientras a*b>10000.
*/

#include <bits/stdc++.h>
using namespace std;

struct sep_num{
    int L1,L2,R1,R2;
};

bool comp(const sep_num &a, const sep_num &b) {
    if (a.R2 == b.R2) {
        if (a.L1 == b.L1) {
            if (a.L2 == b.L2) {
                return a.R1 < b.R1;
            } else {
                return a.L2 < b.L2;
            }
        } else {
            return a.L1 < b.L1;
        }
    } else {
        return a.R2 < b.R2;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int L1, L2, R1, R2; 
    char dot;
    
    vector <sep_num> v;
    
    int lim1 = 25600/3; //La cota del intervalo es 256.
    
    for (L1 = 1; L1 < lim1; L1++) {
        int lim2 = (25600 - L1) / 2; //Con lim1 controlamos el valor de a, con lim2 controlamos el valor de b.
        for (L2 = L1; L2 < lim2; L2++) {
            int x = L1 + L2;
            int y = L1 * L2;
            if (y <= 10000) continue;
            R1 = 10000 * x / (y - 10000);
            R2 = x + R1;
            if (L2 > R1 || R2 > 25600) continue;
            if (R2 == y * R1 / 10000) {
                sep_num tmp;
                tmp.L1 = L1;
                tmp.L2 = L2;
                tmp.R1 = R1;
                tmp.R2 = R2;
                v.push_back(tmp);
            }
        }
    }

    sort(v.begin(), v.end(), comp);
    
    cin >> L1 >> dot >> L2 >> R1 >> dot >> R2;
    
    int start = L1*100 + L2, end = R1*100 + R2;
    
    cout <<  fixed << setprecision(2);
    for (int i = 0, sz = v.size(); i < sz; i++) {
        if (v[i].R2 >= start && v[i].R2 <= end) {
            cout << (v[i].R2/100+ (float)(v[i].R2%100)/100) << " = ";
            cout << (v[i].L1/100+ (float)(v[i].L1%100)/100) << " + " << (v[i].L2/100+ (float)(v[i].L2%100)/100) << " + " << (v[i].R1/100+ (float)(v[i].R1%100)/100) << " = ";
            cout << (v[i].L1/100+ (float)(v[i].L1%100)/100) << " * " << (v[i].L2/100+ (float)(v[i].L2%100)/100) << " * " << (v[i].R1/100+ (float)(v[i].R1%100)/100) << endl;
            
        }
    }
    
    
    return 0;
}