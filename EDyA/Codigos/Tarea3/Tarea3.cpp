// C++ program to implement persistent segment
// tree.
#include "bits/stdc++.h"
using namespace std;

#define MAXN 10001
#define mid(l, r) (l+r)/2

struct Node
{
	int val;

	Node* left, *right;


	Node(Node* l, Node* r) : val(0), left(l), right(r)
	{
		if(l) val += l->val;
		if(r) val += r->val;
	}
};

void build(Node* n, int l, int r)
{
	if (l==r)
	{
		return;
	}
	n->left = new Node(nullptr, nullptr);
	n->right = new Node(nullptr, nullptr);
	build(n->left, l, mid(l, r));
	build(n->right, mid(l, r) + 1, r);
}

void upd(Node* node, int l, int r,  int i, int x){
        if(l == r){
            node->val += x;
            return;
        }

        Node* new_node = new Node(nullptr, nullptr);
        if(i <= mid(l, r)){
            *new_node = *(node->left);
            node->left = new_node;
            upd(l, mid(l, r), new_node, i, x);
        }else{
            *new_node = *(node->left);
            node->left = new_node;
            upd(mid(l, r)+1, r, new_node, i, x);
        }

        node->val = node->left->val + node->left->val;
        return;
}


int query(Node* nodeL, Node* nodeR, int L, int R, int k)
{
	if(L == R) return L;

    int left_count = nodeR->left->val - nodeL->left->val;
    if(left_count >= k) return query(nodeL->left, nodeR->left, L, mid(L, R), k-left_count);
    return query(nodeL->right, nodeR->right, mid(L, R) + 1, R, k-left_count);
}

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n;

    vector<Node*> roots;
    vector<int> a(n);

    Node* root = new Node(nullptr, nullptr);
    build(root, 0, n-1);
    roots[0] = root;
    
	for(int i=0; i<n; i++) 
	    cin >> a[i];

	Node* root = new Node(nullptr, nullptr);
	build(root, 0, n-1);


	return 0;
}
