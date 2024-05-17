#include "TreeProperties.h"

// In full binary tree, every node has either 0 or 2 children
bool isFullBinaryTree(TreeNode* node) {
    if (node == nullptr) return true;
    if ((node->left == nullptr && node->right == nullptr) || (node->left != nullptr && node->right != nullptr))
        return isFullBinaryTree(node->left) && isFullBinaryTree(node->right);
    return false;
}

// In complete binary tree all nodes are fully filled except possibly the last
bool isCompleteBinaryTree(TreeNode* node) {
    if (node == nullptr) return true;
    std::queue<TreeNode*> q;
    q.push(node);
    bool detectedNull = false;
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr == nullptr) detectedNull = true;
        else {
            if (detectedNull) return false;
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return true;
}

// Calculating depth of the binary tree
int depthOfBinaryTree(TreeNode* node) {
    int depth = 0;
    while (node != nullptr) {
        depth++;
        node = node->left;
    }
    return depth;
}
