#include <iostream>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

template <class T>
struct ListNode {
    T val;
    ListNode<T> *next;
    ListNode(T val) : val(val), next(nullptr) {};
};

template <typename T>
ListNode<T>* toListNode(vector<T> input) {
    int size = input.size();
    ListNode<T>* tmp = new ListNode<T>(input[0]);
    ListNode<T>* res = tmp;
    rep(i,size-1) {
        tmp->next = new ListNode<T>(input[i+1]);
        tmp = tmp->next;
    }
    return res;
}

template <typename T>
void show(ListNode<T>* node) {
    while(node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    string s; cin >> s;
    int n = s.length();
    vector<char> cs(n);
    rep(i,n) cs[i] = s[i];
    ListNode<char> *node = toListNode<char>(cs);
    ListNode<char> *first = node->next->next;
    ListNode<char> *second = node->next;
    while(first->next != nullptr && first->next->next != nullptr) {
        first = first->next->next;
        second = second->next;
        if(first->val == second->val) {
            break;
        }
    }
    if(first==nullptr || first->second == nullptr) {
        cout << "could not find" << endl;
    }
    second = node;
    while(second->val != first->val) {
        second = second->next;
        first = first->next;
    }
    show(first);

    return 0;
}