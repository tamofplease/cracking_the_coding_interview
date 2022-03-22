#include "linked_list.c"

using namespace std;


int getLength(ListNode* node) {
    if(node->next == nullptr) return 1;
    return 1 + getLength(node->next);

}

int main() {
    int n,m; cin >> n >> m;
    vector<int> f(n), s(m);
    rep(i,n) cin >> f[i];
    rep(i,m) cin >> s[i];
    ListNode* first = toListNode(f);
    ListNode* second = toListNode(s);

    int fl = getLength(first);
    int sl = getLength(second);

    /// 
    rep(i,sl-fl) second = second->next;
    rep(i,fl-sl) first = first->next;
    ListNode* ans = nullptr;
    while(first != nullptr) {
        if(second->val != first->val) ans = nullptr;
        if(second->val == first->val && ans == nullptr) ans=first;
        first = first->next;
        second = second->next;
    }
    show(ans);
    return 0;
}