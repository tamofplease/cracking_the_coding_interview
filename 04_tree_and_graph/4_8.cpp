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

int get_depth(TreeNode* node) {
    int depth = 0;
    while(node->parent != nullptr) {
        node = node->parent;
    }
    return depth;
}


TreeNode* get_n_ancestor(TreeNode* node, int n) {
    rep(i,n) node = node->parent;
    return node;
}
/// O(max(depth(first), depth(second)))
TreeNode* get_common_ancestor(TreeNode* first, TreeNode* second) {
    int first_depth = get_depth(first);
    int second_depth = get_depth(second);
    int diff = abs(first_depth - second_depth);
    if(second_depth < first_depth) first = get_n_ancestor(first, diff);
    if(first_depth < second_depth) second = get_n_ancestor(second, diff);
    while(first != nullptr && second != nullptr && first != second) {
        first = first->parent;
        second = second->parent;
    }
    if(first == nullptr || second == nullptr) return nullptr;
    return first;
}

int main() {
    
    return 0;
}