#include <bits/stdc++.h>

using namespace std;

struct Node{
    long long key;
    Node *left, *right;

    Node(long long x){
        key = x;
        left = right = nullptr;
    }
};

typedef Node* pNode;

void insertNode(pNode &v, long long x){
    if (v == nullptr){
        v = new Node(x);
        return;
    }

    if(v->key == x) return;

    if(x < v->key)
        insertNode(v->left, x);
    else insertNode(v->right, x);
}

pNode root;

void preOrder(pNode v){
    if(v == nullptr) return 0;


    cout << v->key << endl;
    preOrder(v->left);
    preOrder(v->right);
}

long long x, ma;

int main(){
    root = nullptr;
    while(cin >> x)
    {
        if (x == 0)
            break;
        insertNode(root, x);
    }

    ma = maxDepth(root);
    cout << ma << endl;

    return 0;
}
