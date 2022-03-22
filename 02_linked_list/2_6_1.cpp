#include "linked_list.c"

using namespace std;

// O(N)
// O(N)
/// 1->3->5->6
/// 1<-3<-5<-6
ListNode* reverseAndClone(ListNode* node) {
    ListNode* prev = nullptr;
    node = node->next;
    while(node != nullptr) {
        ListNode* newNode = new ListNode(node->val);
        newNode->next = prev;
        node = node->next;
        prev = newNode;
    }
    return prev;
}
bool checkIsPalindrome(ListNode* node) {
    ListNode* reversed = reverseAndClone(node);
    while(reversed != nullptr) {
        if(reversed->val != node->val) {
            return false;
        }
        reversed = reversed->next;
        node = node->next;
    }
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