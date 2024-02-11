#include <bits/stdc++.h>
using namespace std;


struct ST{
    int n;
    vector<int> a, st;

    ST(vector<int> &a){
        n = a.size();
        this->a = a;
        st.resize(4*n + 1);
        build(0, n-1, 0);
        return;
    }

    void build(int l, int r, int nd){
        if(l == r){
            st[nd] = a[l];
            return;
        }
        build(l, mid(l, r), leftCh(nd));
        build(mid(l, r)+1, r, rightCh(nd));
        st[nd] = max(st[leftCh(nd)], st[rightCh(nd)]);
        return;
    }


    int nxtGreaterEq(int l, int r, int nd, int x){
        if(st[nd] < x) return -1;
        if(l == r){
            a[l] = st[nd] = a[l]-x;
            return l;
        }

        int ans = -1;
        if(st[leftCh(nd)] >= x) ans = nxtGreaterEq(l, mid(l, r), leftCh(nd), x);
        else ans = nxtGreaterEq(mid(l, r)+1, r, rightCh(nd), x);

        st[nd] = max(st[leftCh(nd)], st[rightCh(nd)]);

        return ans;
    }

    int nxtGreaterEq(int x){
        return nxtGreaterEq(0, n-1, 0, x);
    }

private:
    inline int mid(int l, int r){ return (l + r)/2; }
    inline int leftCh(int nd){ return 2*nd+1; }
    inline int rightCh(int nd){ return 2*nd+2; }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m,x;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    ST st(a);
    for(int i=0; i<m; i++){
        cin >> x;
        cout << st.nxtGreaterEq(x)+1 << " ";
    }
    cout << "\n";

    return 0;
}
