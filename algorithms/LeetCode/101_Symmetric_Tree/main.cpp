#include <bits/stdc++.h>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return helper(root->right, root->left);
    }

    bool helper(TreeNode* node1, TreeNode* node2) {
        if (node1 == NULL || node2 == NULL) {
            return node1 == node2;
        }
        return node1->val == node2->val && helper(node1->left, node2->right) && helper(node2->left, node1->right);
    }
};