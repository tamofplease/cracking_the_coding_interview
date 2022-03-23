#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {};
    Node(int val, Node* left, Node* right) : val(val), left(left), right(right) {};
};

//      4
//     / \
//    2   5
//   / \   \
//  1   3   6

/// [1,2,3,4,5] = 5
/// 0,5 =>  3 5
///     =>  0 2

/// [1,2,3,4,5,6] => 6
/// 0,6 => 4 6
///     => 0 3
Node* create_binary_tree(vector<int>& x, int left, int right) {
    if(left > right) return nullptr;
    int mid = (left + right) / 2;
    int val = x[mid];

    Node* leftNode = create_binary_tree(x, left, mid-1);
    Node* rightNode = create_binary_tree(x, mid+1, right);
    
    return new Node(val, leftNode, rightNode);
}
int main() {
    int n; cin >> n;
    vector<int> x(n);
    rep(i,n) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    Node* ans = create_binary_tree(x, 0, n-1);
    queue<Node*> q;
    q.push(ans);
    while(!q.empty()) {
        Node* node = q.front(); q.pop();
        cout << node->val << endl;
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if(node->right != nullptr) {
            q.push(node->right);
        }
    }


    return 0;
}