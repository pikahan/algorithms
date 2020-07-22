#include <bits/stdc++.h>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    vector<TreeNode*> helper(int leftBound, int rightBound) {
        if (rightBound < leftBound) {
            return  { nullptr };
        }
        vector<TreeNode*> ret;
        for (int i = leftBound; i <= rightBound; i++) {
            auto leftNodes = helper(leftBound, i-1);
            auto rightNodes = helper(i+1, rightBound);

            for (auto leftNode: leftNodes) {
                for (auto rightNode: rightNodes) {
                    auto root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            return {};
        }

        return helper(1, n);
    }
};