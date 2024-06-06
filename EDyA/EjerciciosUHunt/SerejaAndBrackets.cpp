/*Construimos un Segment Tree a partir de la cadena de paréntesis, donde cada
nodo almacena la información sobre subsecuencias válidas y paréntesis sobrantes.
Para cada query, se combina la información de los nodos hijos para calcular la 
longitud de la máxima subsecuencia válida en el rango especificado.*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int validos; // Longitud de la máxima subsecuencia válida
    int abre; // Número de '(' sobrantes
    int cierra; // Número de ')' sobrantes

    Node() : validos(0), abre(0), cierra(0) {}
    Node(int validos, int abre, int cierra) : validos(validos), abre(abre), cierra(cierra) {}
};

class SegmentTree {
private:
    vector<Node> tree;
    int n;

    Node combine(Node left, Node right) {
        Node res;
        int match = min(left.abre, right.cierra);
        res.validos = left.validos + right.validos + 2 * match;
        res.abre = left.abre + right.abre - match;
        res.cierra = left.cierra + right.cierra - match;
        return res;
    }

    void build(const string &s, int v, int tl, int tr) {
        if (tl == tr) {
            if (s[tl] == '(') {
                tree[v] = Node(0, 1, 0);
            } else {
                tree[v] = Node(0, 0, 1);
            }
        } else {
            int tm = (tl + tr) / 2;
            build(s, v * 2, tl, tm);
            build(s, v * 2 + 1, tm + 1, tr);
            tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return Node();
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return combine(
            query(v * 2, tl, tm, l, min(r, tm)),
            query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    }

public:
    SegmentTree(const string &s) {
        n = s.size();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);
    }

    int getValidos(int l, int r) {
        return query(1, 0, n - 1, l, r).validos;
    }
};

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    SegmentTree segTree(s);
    
    while(m--){
        int l, r;
        cin >> l >> r;
        cout << segTree.getValidos(l-1, r-1)<< endl;
    }

    return 0;
}
