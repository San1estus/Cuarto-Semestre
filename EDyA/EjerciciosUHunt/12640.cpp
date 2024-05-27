/*Cuarta edición*/
#include <bits/stdc++.h>
#define max(a,b) a < b ? b : a
using namespace std;

vector<int> string2Arreglo(const string &str) {
    vector<int> result;
    stringstream ss(str);
    string temp;
    
    while (ss >> temp) {
        int number = stoi(temp); 
        result.push_back(number); 
    }
    
    return result;
}
/*dp[i] representa el maximo entre la suma de dp[i-1] y el numero actual
y el numero actual, si dp[i] llegar a tomar un valor negativos, entonces
el valor cambiaria si el numero actual es mayor a ese negativo, resp
registra el maximo total alcanzado hasta el i-esimo numero.*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    freopen("input.in", "r", stdin);
    freopen("input.out", "w", stdout);
    while(getline(cin, s)){
        vector<int> nums = string2Arreglo(s);
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        int resp = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = max(dp[i-1] + nums[i-1], nums[i-1]);
            resp = max(resp, dp[i]);
        }   
        cout << resp << endl;
    }
    return 0;
}
