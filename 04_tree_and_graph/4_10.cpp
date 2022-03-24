#include <iostream>
#include "tree_node.cpp"

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)


/// O(nodes(t1))
bool simple_solution(TreeNode* t1, TreeNode* t2) {
    if(t1 == nullptr && t2 == nullptr) return true;

    if(t1 == nullptr ^ t2 == nullptr) return false;

    if(t1->val == t2->val) {
        if(simple_solution(t1->left, t2->left) && simple_solution(t1->right, t2->right)) {
            return true;
        };
    }
    return simple_solution(t1->left, t2) || simple_solution(t1->right, t2);
}





int main() {

    return 0;
}