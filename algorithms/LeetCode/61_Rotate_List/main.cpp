#include <bits/stdc++.h>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        auto tempNode = head;

        int n = 1; // 计算节点个数
        while (tempNode->next != NULL) {
            n++;
            tempNode = tempNode->next;
        }
        tempNode->next = head; // 成环

        for (int i = 0; i < n - k % n; i++) {
            tempNode = tempNode->next;
        }
        auto ret = tempNode->next;
        tempNode->next = NULL;

        return ret;
    }
};