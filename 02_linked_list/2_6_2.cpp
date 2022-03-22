#include "linked_list.c"

using namespace std;

bool isEven(ListNode* node) {
    bool isEven = true;
    while(node != nullptr) {
        node = node->next;
        isEven = !isEven;
    }
    return isEven;
}

ListNode* getMid(ListNode* head) {
    ListNode* one = head;
    ListNode* two = head->next;
    while(two != nullptr && two->next != nullptr) {
        two = two->next->next;
        one = one->next;   
    }
    return one;
}

ListNode* check(ListNode* node) {
    ListNode* mid = getMid(node);
    cout << mid->val << endl;
    if(isEven(node)) {
        
    }

}

bool checkIsPalindrome(ListNode* node) {
    check(node);
    return true;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    ListNode* node = toListNode(v);
    cout << (checkIsPalindrome(node)?"Yes":"No") << endl;
    return 0;
}