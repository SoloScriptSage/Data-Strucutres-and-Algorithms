#include <bits/stdc++.h>
#include "TreeNode.h"
#include "TreeTraversal.h"
#include "TreeProperties.h"

#define fast ios_base::sync_with_stdio(false)

using namespace std;

TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

void showAllTraversals(TreeNode* root) {
    cout << "Pre-order traversal: ";
    PreOrderTraversal(root);
    cout << endl;

    cout << "In-order traversal: ";
    InOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    PostOrderTraversal(root);
    cout << endl;

    cout << "Level order traversal: ";
    LevelOrderTraversal(root);
    cout << endl;
}

int main() {
    fast;
    TreeNode* root = createTree();
    showAllTraversals(root);
    
    // Checking if binary tree is full
    if (isFullBinaryTree(root)) 
        cout << "Binary tree is full, and has either 0 or 2 children" << endl;
    else 
        cout << "Binary tree isn't full, because some node has 1 child" << endl;
    
    // Checking if binary tree is complete
    if (isCompleteBinaryTree(root)) 
        cout << "Binary tree is complete" << endl;
    else 
        cout << "Binary tree isn't complete" << endl;

    cout << "Depth of binary tree is: " << depthOfBinaryTree(root) << endl;

    return 0;
}
