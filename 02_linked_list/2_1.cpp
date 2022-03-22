#include <iostream>
#include <vector>
#include <set>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* input(vector<int>& sample) {
    if(sample.size() < 1) return nullptr;
    ListNode* head = new ListNode(sample[0]);
    if(sample.size() < 2) return head;
    ListNode* cur = new ListNode(sample[1]);
    head->next = cur;
    for(int i=2;i<sample.size();i++) {
        cur->next = new ListNode(sample[i]);
        cur = cur->next;
    }
    return head;
}


/// TODO refactor
ListNode* solve(ListNode* head) {
    ListNode* root = head;
    /// handle case when lsitNode size is only one or zero item;
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* next = head->next;
    ListNode* next_next = head->next->next;
    /// handle case there are only two items;
    if(next_next == nullptr) {
        if(head->val == next->val) return next;
        else return head;
    }


    /// case there are more than three items;
    set<int> se;
    while(next_next != nullptr) {
        se.insert(head->val);
        if(se.find(next->val) != se.end()) {
            head->next = next_next;
        } else {
            head = next;
        }
        next = next_next;
        next_next = next_next->next;
    }
    return root;
}

/// without buffer
ListNode* solve_exp(ListNode* head) {
    ListNode* ans = head;
    while(head != nullptr) {
        int target = head->val;
        ListNode* runner = head;
        while(runner->next != nullptr) {
            if(runner->next->val == target) {
                runner->next = runner->next->next;
            } else {
                runner = runner->next;
            }
        }
        head = head->next;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    ListNode* head = input(v);
    ListNode* ans = solve_exp(head);
    while(ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}