#include "TreeTraversal.h"

using namespace std;

// Preorder traversal: Root -> Left -> Right
void PreOrderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->value << " ";
    PreOrderTraversal(node->left);
    PreOrderTraversal(node->right);
}

// In-order traversal: Left -> Root -> Right
void InOrderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    InOrderTraversal(node->left);
    cout << node->value << " ";
    InOrderTraversal(node->right);
}

// Post-order traversal: Left -> Right -> Root
void PostOrderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    PostOrderTraversal(node->left);
    PostOrderTraversal(node->right);
    cout << node->value << " ";
}

// Level Order Traversal: Level by level
void LevelOrderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    queue<TreeNode*> q;
    q.push(node);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        cout << curr->value << " ";
        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }
}
