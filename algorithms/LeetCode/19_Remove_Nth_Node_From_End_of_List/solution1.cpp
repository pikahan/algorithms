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

// 两次遍历

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* curr = head;

        while (curr) {
            len++;
            curr = curr->next;
        }
        n = len - n;

        if (n == 0) return head->next;
        curr = head;
        int pos = 1;
        do {
            if (pos == n) {
                curr->next = curr->next->next;
                break;
            }
            pos++;
            curr = curr->next;
        } while (curr);
        return head;
    }
};