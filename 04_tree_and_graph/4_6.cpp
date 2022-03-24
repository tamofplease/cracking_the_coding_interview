#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode* parent;
    TreeNode(int val, TreeNode* parent) : val(val), right(nullptr), left(nullptr), parent(parent) {};
}

TreeNode* next_node(TreeNode* node) {
    if(node == nullptr) return nullptr;

    if(node->right != nullptr) {
        return most_left_child(node->right);
    }
    TreeNode* parent = node->parent;
    if(parent == nullptr) {
        return nullptr;
    }
    if(parent->left == node) {
        return parent;
    } else {
        while(parent != null && parent->left != node) {
            node = parent;
            parent = parent->parent;
        }
        return node;
    }
}

TreeNode* most_left_child(TreeNode* node) {
    if(node == nullptr) return nullptr;
    while(node->left != nullptr) node = node->left;
    return node;
}

int main() {
    
    return 0;
}