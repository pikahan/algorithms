//
// Created by 杨寒凌 on 2020/6/5.
//

#include <bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* curr = dummyHead;
        while (curr->next && curr->next->next) {
            ListNode* node1 = curr->next;
            ListNode* node2 = curr->next->next;
            curr->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            curr = curr->next->next;
        }
        return dummyHead->next;
    }
};