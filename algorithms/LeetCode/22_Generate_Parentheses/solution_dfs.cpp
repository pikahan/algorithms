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



class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        dfs("", n, n, ret);
        return ret;
    }

    void dfs(string currentString, int leftParenthesisNumber, int rightParenthesisNumber, vector<string>& result) { // 必须加速&符号
        if (leftParenthesisNumber == 0 && rightParenthesisNumber == 0) {
            return result.push_back(currentString);
        }

        if (leftParenthesisNumber > 0) {
            dfs(currentString+'(', leftParenthesisNumber-1, rightParenthesisNumber, result);
        }

        if (leftParenthesisNumber < rightParenthesisNumber) {
            dfs(currentString+')', leftParenthesisNumber, rightParenthesisNumber-1, result);
        }
    }
};

int main() {
    Solution().generateParenthesis(3);
}