//
// Created by 杨寒凌 on 2020/5/31.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <bits/stdc++.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummyHead = new ListNode(0);
        auto currNode = dummyHead;
        int curry = 0;
        while (l1 != NULL || l2 != NULL) {
            int val1 = l1 == NULL ? 0 : l1->val;
            int val2 = l2 == NULL ? 0 : l2->val;
            int sum = val1 + val2 + curry;
            curry = sum / 10;
            currNode->next = new ListNode(sum % 10);
            currNode = currNode->next;

            if (l1 != NULL) {
                l1 = l1->next;
            }

            if (l2 != NULL) {
                l2 = l2->next;
            }

        }
        if (curry) {
            currNode->next = new ListNode(1);
        }

        return dummyHead->next;

    }
};