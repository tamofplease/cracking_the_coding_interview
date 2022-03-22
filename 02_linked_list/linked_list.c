#pragma once

#include <iostream>
#include <vector>

#define rep(i,n) for(int i=0;i<n;i++)

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {};
};


ListNode* toListNode(std::vector<int>& sample) {
    ListNode* head = new ListNode(sample[0]);
    ListNode* res = head; 
    rep(i, sample.size()-1) {
        int s = sample[i+1];
        ListNode* newNode = new ListNode(s);
        head->next = newNode;
        head = head->next;
    }
    return res;
}

void show(ListNode* node) {
    while(node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}
