/*Cuarta edición*/
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int H, P, O;
    while(cin >> P >> H >> O){
        if(P > O - H) cout << "Hunters win!" << endl;
        else cout << "Props win!" << endl;
    }

    return 0;
}