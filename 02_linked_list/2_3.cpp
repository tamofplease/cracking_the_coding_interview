#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {};
};


ListNode* toListNode(vector<int>& sample) {
    ListNode* head = new ListNode(sample[0]);
    ListNode* res = head; 
    rep(i, sample.size() - 1) {
        int s = sample[i+1];
        ListNode* newNode = new ListNode(s);
        head->next = newNode;
        head = head->next;
    }
    return res;
}

bool removeNode(ListNode* node) {
    if(node == nullptr || node->next == nullptr) {
        return false;
    }
    node->val = node->next->val;
    node->next = node->next->next;
    return true;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    ListNode* node = toListNode(v);
    
    return 0;
}