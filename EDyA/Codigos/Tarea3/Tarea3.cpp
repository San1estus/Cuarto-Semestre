#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;

typedef tree<
pair<int,int>,
null_type,
less< pair<int,int> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

struct ST{
    int n;
    vector<int> a;
    vector<ordered_set> st;

    ST(vector<int> &a){
        this->a = a;
        n = a.size();
        st.resize(4*n);
        build(0, n-1, 0);
        return;
    }

    void build(int l, int r, int nd){
        if(l == r){
            st[nd].insert({a[l],l});
            return;
        }
        build(l, mid(l, r), leftCh(nd));
        build(mid(l, r)+1, r, rightCh(nd));

        st[nd] = st[leftCh(nd)];
        for(auto x: st[rightCh(nd)]) st[nd].insert(x);
        return;
    }

    int qry(int l, int r, int nd, int L, int R, int x){
        if(r < L || l > R) return 0;
        if(L <= l && r <= R) return st[nd].size() - st[nd].order_of_key({x, n+1});
        return qry(l, mid(l, r), leftCh(nd), L, R, x) + qry(mid(l, r)+1, r, rightCh(nd), L, R, x);
    }

    int qry(int l, int r,  int x){
        return qry(0, n-1, 0, l, r, x);
    }

private:
    inline int mid(int l, int r){ return (l + r)/2; }
    inline int leftCh(int nd){ return 2*nd+1; }
    inline int rightCh(int nd){ return 2*nd+2; }
};



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    ST st(a);
    int l, r, x;
    cin >> m;
    while(m--){
        cin >> l >> r >> x;
        l--; r--;
        cout << st.qry(l, r, x) << "\n";
    }
    return 0;
}
