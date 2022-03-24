#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

bool is_binary_search_tree(TreeNode* node, int min, int max) {
    if((min != null && node->val < min) || (max != null && max < node->val)) return false;
    bool res = true;
    if(node->right != nullptr) {
        if(node->val > node->right->val) return false;
        res = is_binary_search_tree(node->right, min(node->val, min), max);
    }
    if(node->left != nullptr) {
        if(node->val < node->left->val) return false;
        res = res & is_binary_search_tree(node->left, min, max(max, node->val));
    }
    return res;
}

int main() {
    
    return 0;
}