//
// Created by 杨寒凌 on 2020/6/4.
//

#include <bits/stdc++.h>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 一次遍历

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* first = dummyNode;
        ListNode* second = dummyNode;
        int count = 0;

        while (first->next) {
            if (count < n) {
                first = first->next;
                count++;
            } else {
                first = first->next;
                second = second->next;
            }
        }

        second->next = second->next->next;
        return dummyNode->next;
    }
};