#include <bits/stdc++.h>
using namespace std;

struct Node{
    long long sum;
    Node *leftCh, *rightCh;

    Node(){
        sum = 0;
        leftCh = rightCh = nullptr;
    }
};


struct PST{
    int n;
    vector<Node*> roots;
    PST(int n){
        this->n = n;
        roots.push_back(new Node);
        build(0, n-1, roots[0]);
        return;
    }

    void build(int l, int r, Node* node){
        if(l == r) return;
        node->leftCh = new Node;
        node->rightCh = new Node;
        build(l, mid(l, r), node->leftCh);
        build(mid(l, r)+1, r, node->rightCh);
        node->sum = node->leftCh->sum + node->rightCh->sum;
        return;
    }

    void upd(int l, int r, Node* node, int i, int x){
        if(l == r){
            node->sum += x;
            return;
        }

        Node* new_node = new Node;
        if(i <= mid(l, r)){
            *new_node = *(node->leftCh);
            node->leftCh = new_node;
            upd(l, mid(l, r), new_node, i, x);
        } else{
            *new_node = *(node->rightCh);
            node->rightCh = new_node;
            upd(mid(l, r)+1, r, new_node, i, x);
        }

        node->sum = node->leftCh->sum + node->rightCh->sum;
        return;
    }

    void upd(int i, int x){
        Node old_root = *roots.back();
        roots.push_back(new Node);
        *roots.back() = old_root;
        upd(0, n-1, roots.back(), i, x);
        return;
    }

    int qry(Node* nodel, Node* noder, int k, int l, int r){
        if (l == r) {
        return l;
    }

    int left_count = noder->leftCh->sum - nodel->leftCh->sum;

    if (left_count >= k) {
        return qry(nodel->leftCh, noder->leftCh, l, mid(l, r), k);
    }

    return qry(nodel->rightCh, noder->rightCh, mid(l, r) + 1, r, k - left_count);
    }

    long long qry(int l, int r, int k){
        return qry(roots[l], roots[r], k, 0, n-1);
    }

private:
    inline int mid(int l, int r){ return (l + r)/2; }
};


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n;
    vector<int> a(n);

    return 0;
}
