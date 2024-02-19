#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int min(int a, int b){
    return a < b ? a : b;
}

int main(void){
    freopen("mixmilk.in", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int capacity, milk;
    vector<pair<int,int>> buckets(3);
    cin >> capacity >> milk;
    buckets.push_back({capacity, milk});

    for(int i = 0; i < 100; i++){
        int amount = min(buckets[i % 3].second, buckets[(i + 1) % 3].first - buckets[(i + 1) % 3].second);

        buckets[i % 3].second -= amount;
        buckets[(i + 1) % 3].second += amount;
    }
    
    freopen("mixmilk.out", "w", stdout);
    
    for(int i = 0; i < 3; i++){
        cout << buckets[i].second << endl;
    }
}