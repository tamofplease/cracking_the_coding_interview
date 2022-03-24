#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int getHeight(TreeNode* node) {
    if(node == nullptr) return -1;

    int rightHeigh = getHeight(node->right);
    if(rightHeigh == INT_32MIN) return INT_32MIN;
    int leftHeigh = getHeight(node->left);
    if(leftHeigh == INT_32MIN) return INT_32MIN;
    if(abs(rightHeigh - leftHeigh) > 1) return INT_32MIN;

    return max(rightHeigh, leftHeigh)
}

bool isBalanced(TreeNode* node) {
    return getHeight(node) != INT_32MIN;
}

int main() {
    
    return 0;
}