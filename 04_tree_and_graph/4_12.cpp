#include <iostream>
#include "tree_node.cpp"

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int find_sum(TreeNode* node, int sum) {
    if(node == nullptr && sum == 0) return 1;
    if(node == nullptr && sum != 0) return 0;
    if(sum < 0) return 0;
    int rightSum = find_sum(node->right, sum) + find_sum(node->right, sum-node->val);
    int leftSum = find_sum(node->left, sum) + fund_sum(node->left, sum-node->val);
    return rightSum + leftSum;
}

int target;

int optimize_find_sum(TreeNode* node, int cur, map<int,int> ma) {
    if(node == nullptr) {
        if(ma.find(cur-target) == ma.end()) return 0;
        return ma[cur-target];
    }
    cur += node->val;
    int ans = 0;
    if(cur == target) {
        ans++;
    }
    ma[cur]++;
    ans += optimize_find_sum(node->left, cur, ma) + optimize_find_sum(node->right, cur, ma);
    ma[cur]--;
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    TreeNode* root = fromVector(v);
    int sum; cin >> sum;
    target = sum;
    cout << find_sum(root, sum) << endl;

    return 0;
}