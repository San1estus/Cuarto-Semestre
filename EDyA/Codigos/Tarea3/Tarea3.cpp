#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std; 
using namespace __gnu_pbds; 

#define vi vector<int> 
#define pii pair<int, int>
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update> 
#define N_MAX 20001
#define mid(i,j) (i+j)/2

struct SegmentTree{
    vi A; 
    vector<ordered_set>  st; 
    int n; 

    SegmentTree(vi &arr){
        A = arr;  
        n = (int)A.size(); 
        st.assign(4 * n, ordered_set());
        build (1, 0 , n-1); 
        return;
    }
    
    int left (int p) {return 2 * p;} 
    int right(int p) {return 2 * p + 1;} 

    void build (int p, int L, int R)
    {
        if (L == R){ 
            st[p].insert({A[L], L});
            return;
        }   

        build(left(p), L, (L+R)/2); 
        build(right(p), (L+R)/2 + 1, R); 
            
        st[p] = st[left(p)]; 

        for(auto x: st[right(p)]) st[p].insert(x);
        return;
    } 

    int qry(int l, int r, int p, int L, int R, int x){
        if(r < L || l > R) return 0;
        
        if(L <= l && r <= R) return st[p].order_of_key( {x+1,-1} );
        
        int izq = qry(l, mid(l, r), left(p), L, R, x);
        int der = qry(mid(l, r)+1, r, right(p), L, R, x);
        return  izq + der;
    }

    int qry(int l, int r,  int x){
        return qry(0, n-1, 1, l, r, x);
    }
    
    int binary_search (int L, int R, int k) 
    {     
        int mid, i = 0, j = 100000;
        while(i != j){
            mid = (i+j)/2;

            if( qry(L, R, mid) <= k ){
                i = mid+1;
            } else{
                j = mid;
            }
        }
         
        return i;
    }



void update (int p, int L, int R, int idx, int val) 
    { 
        if(R < idx || idx < L)  return;

        st[p].erase({A[idx], idx});
        st[p].insert({val, idx});
        
        int mid = (L+R)/2;

        if(L != R){
            update(left(p), L, mid, idx, val); 
            update(right(p), mid + 1, R, idx, val);  
        }

        return; 
    
    }

    void update (int idx, int val) 
    {  
        update(1, 0, n-1, idx, val); 
        A[idx] = val;
    }
    
};


int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, query; 

    cin >> N; 
    
    vi arr(N);
     
    for (int i = 0; i < N ; ++i)
     cin >> arr[i]; 

    SegmentTree st(arr); 

    cin >> M; 

    while(M--){
        cin >> query;
        if(query == 0){
            int l, r, k;
            cin >> l >> r >>k;
            cout << st.binary_search(l, r, k) << endl;
        }
        
        if(query == 1){
            int idx, val;
            cin >> idx >> val;
            st.update(idx, val);
        }
    }


    return 0;
}