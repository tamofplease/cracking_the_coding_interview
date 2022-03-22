#include <iostream>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

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

ListNode* separateWithN(ListNode* node, int n) {
    ListNode* smaller = new ListNode(-1);
    ListNode* other = new ListNode(-1);
    ListNode* ans; /// head pointer of small;
    ListNode* tmp; /// head pointer of other;
    while(node != nullptr) {
        if(node->val < n) {
            if(smaller->val == -1) {
                smaller = node;
                ans = smaller;
            } else {
                smaller->next = node;
                smaller = smaller->next;
            }
        } else {
            if(other->val == -1) {
                other = node;
                tmp = other;
            } else {
                other->next = node;
                other = other->next;
            }
        }
        node = node->next;
    }
    other->next = nullptr;
    smaller->next = tmp;
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    ListNode* head = toListNode(v);
    int x; cin >> x;
    ListNode* ans = separateWithN(head, x);
    while(ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}