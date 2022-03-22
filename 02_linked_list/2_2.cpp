#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {};
};


ListNode* input(vector<int>& sample) {
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

/// list: 2 3 4 5 6
/// k = 3
/// ans = 4
/// 
int findK(int k, ListNode* head) {
    ListNode* front = head;
    rep(i,k-1) {
        if(front->next == nullptr) return -1;
        front = front->next;
    }
    /// eg: fromt->val = 4
    ListNode* prev = head;
    while(front->next != nullptr) {// (3,5) => (4,6)
        front = front->next;
        prev = prev->next;
    }
    return prev->val;
}

int main() {
    int n; cin >> n;
    int k; cin >> k;
    assert(k <= n);
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    ListNode* node = input(v);
    int ans = findK(k, node);
    cout << ans << endl;
    return 0;
}