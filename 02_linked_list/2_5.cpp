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

void show(ListNode* node) {
    while(node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

ListNode* calcSum(ListNode* first, ListNode* second, int carry) {
    if(first==nullptr && second == nullptr) {
        if(carry == 0) return nullptr;
        return new ListNode(carry);
    }
    
    if(first == nullptr) {
        carry += second->val;
        if(carry > 9) {
            second->next = calcSum(first, second->next, carry/10);
        }
        second->val = carry;
        return second;
    }

    if(second == nullptr) {
        carry += first->val;
        if(carry > 9) {
            first->next = calcSum(first->next, second, carry/10);
        }
        first->val = carry;
        return first; 
    }

    carry += first->val + second->val;
    first->val = carry % 10;
    first->next = calcSum(first->next, second->next, carry/10);
    return first;
}

int main() {
    int n; cin >> n;
    vector<int> ns(n);
    int m; cin >> m;
    vector<int> ms(m);
    rep(i,n) cin >> ns[i];
    rep(i,m) cin >> ms[i];
    ListNode* first = toListNode(ns);
    ListNode* second = toListNode(ms);
    ListNode* ans = calcSum(first, second, 0);
    int res = 0;
    int pow = 1;
    show(ans);
    while(ans != nullptr) {
        res += (ans->val * pow);
        pow *= 10;
        ans = ans->next;
    }
    cout << res << endl;
    return 0;
}