#include <iostream>
#include "tree_node.cpp"
#include "linked_list.cpp"
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    int n; cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    BinaryNode* node = fromVector(v);
    cout << node->val << endl;
    vector<LinkedList*> lists(n, nullptr);
    vector<LinkedList*> tops(n, nullptr);
    int maxDepth = 0;
    auto dfs = [&] (auto f, BinaryNode* current_node, int depth) -> void {
        maxDepth = max(maxDepth, depth);
        if(current_node->left != nullptr) {
            f(f, current_node->left, depth+1);
        }
        LinkedList* newNode = new LinkedList(current_node->val);
        if(lists[depth] == nullptr) {
            tops[depth] = newNode;
            lists[depth] = newNode;
        } else {
            lists[depth]->next = newNode;
            lists[depth] = newNode;
        }
        if(current_node->right != nullptr) {
            f(f, current_node->right, depth+1);
        }
    };

    dfs(dfs, node, 0);

    rep(i,maxDepth) {
        LinkedList* cur = tops[i];
        while(cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    return 0;
}