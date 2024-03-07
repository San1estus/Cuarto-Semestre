#include <bits/stdc++.h>
using namespace std;

enum PENDIENTE {
    NADA = 0,
    FIJAR1 = 1,
    FIJAR0 = 2,
    INVERTIR = 3
};

struct ST {

    int n;
    string a;
    vector<int> st;

    vector<PENDIENTE> lzy_tag;

    ST(string &a) {
        this->a = a;
        n = a.size();
        st.resize(4 * n);

        lzy_tag.assign(4 * n, PENDIENTE::NADA);

        build(0, n - 1, 0);
        return;
    }

    void build(int l, int r, int nd) {
        if (l == r) {
            st[nd] = a[l] == '1' ? 1 : 0;
            return;
        }

        build(l, (l + r) / 2, leftCh(nd));
        build((l + r) / 2 + 1, r, rightCh(nd));

        st[nd] = st[leftCh(nd)] + st[rightCh(nd)];
        return;
    }

    void push(int l, int r, int nd) {
        if (lzy_tag[nd] == PENDIENTE::NADA) return;
        if (lzy_tag[nd] == PENDIENTE::FIJAR1) {
            st[nd] = 1LL * (r - l + 1) * 1;
            if (l < r) {
                lzy_tag[leftCh(nd)] = lzy_tag[rightCh(nd)] = PENDIENTE::FIJAR1;
            }
        }

        if (lzy_tag[nd] == PENDIENTE::FIJAR0) {
            st[nd] = 1LL * (r - l + 1) * 0;
            if (l < r) {
                lzy_tag[leftCh(nd)] = lzy_tag[rightCh(nd)] = PENDIENTE::FIJAR0;
            }
        }

        if (lzy_tag[nd] == PENDIENTE::INVERTIR) {
            st[nd] = 1LL * (r - l + 1) - st[nd];
            if (l < r) {
                if (lzy_tag[leftCh(nd)] == PENDIENTE::INVERTIR) lzy_tag[leftCh(nd)] = PENDIENTE::NADA;
                else if (lzy_tag[leftCh(nd)] == PENDIENTE::FIJAR1) lzy_tag[leftCh(nd)] = PENDIENTE::FIJAR0;
                else if (lzy_tag[leftCh(nd)] == PENDIENTE::FIJAR0) lzy_tag[leftCh(nd)] = PENDIENTE::FIJAR1;
                else if (lzy_tag[leftCh(nd)] == PENDIENTE::NADA) lzy_tag[leftCh(nd)] = PENDIENTE::INVERTIR;

                if (lzy_tag[rightCh(nd)] == PENDIENTE::INVERTIR) lzy_tag[rightCh(nd)] = PENDIENTE::NADA;
                else if (lzy_tag[rightCh(nd)] == PENDIENTE::FIJAR1) lzy_tag[rightCh(nd)] = PENDIENTE::FIJAR0;
                else if (lzy_tag[rightCh(nd)] == PENDIENTE::FIJAR0) lzy_tag[rightCh(nd)] = PENDIENTE::FIJAR1;
                else if (lzy_tag[rightCh(nd)] == PENDIENTE::NADA) lzy_tag[rightCh(nd)] = PENDIENTE::INVERTIR;
            }
        }

        lzy_tag[nd] = PENDIENTE::NADA;
        return;
    }

    long long qry(int l, int r, int nd, int L, int R) {
        push(l, r, nd);
        if (r < L || l > R) return 0;
        if (L <= l && r <= R) return st[nd];
        return qry(l, (l + r) / 2, leftCh(nd), L, R) + qry((l + r) / 2 + 1, r, rightCh(nd), L, R);
    }

    long long qry(int l, int r) {
        return qry(0, n - 1, 0, l, r);
    }

    void upd(int l, int r, int nd, int L, int R, PENDIENTE accion) {
        push(l, r, nd);
        if (r < L || l > R) return;
        if (L <= l && r <= R) {
            lzy_tag[nd] = accion;
            push(l, r, nd);
            return;
        }

        upd(l, (l + r) / 2, leftCh(nd), L, R, accion);
        upd((l + r) / 2 + 1, r, rightCh(nd), L, R, accion);
        st[nd] = st[leftCh(nd)] + st[rightCh(nd)];
        return;
    }

    void upd(int l, int r, PENDIENTE accion) {
        upd(0, n - 1, 0, l, r, accion);
        return;
    }

private:
    inline int leftCh(int nd) { return 2 * nd + 1; }
    inline int rightCh(int nd) { return 2 * nd + 2; }
};

string operator * (string a, unsigned int b) {
    string output = "";
    while (b--) {
        output += a;
    }
    return output;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T, M, l, r, times, Q;
    char op;
    cin >> T;
    string a = "", chars;

    while (T--) {
        a="";
        cin >> M;
        while(M--){
            cin >> times;
            cin >> chars;
            a += chars*times;
        }
        
        ST st(a);
        cin >> Q;
        
        while(Q--){
            cin >> op >> l >> r;
            if (op == 'F') {
                st.upd(l, r, PENDIENTE::FIJAR1);
            }
            else if (op == 'E') {
                st.upd(l, r, PENDIENTE::FIJAR0);
            }
            else if (op == 'I'){
                st.upd(l, r, PENDIENTE::INVERTIR);
            }

            else {
                cout << st.qry(l, r) << "\n";
            }
        }
        
    }
    return 0;
}
