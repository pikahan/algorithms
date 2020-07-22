#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        int targetCount = m * n;
        int currCount = 1;
        int topBound = 0;
        int rightBound = n-1;
        int bottomBound = m-1;
        int leftBound = 0;
        while (currCount <= targetCount) {
            for (int i = leftBound; i <= rightBound; i++) {
                ret.push_back(matrix[topBound][i]);
                currCount++;
            }
            if (currCount > targetCount) return ret;
            topBound++;

            for (int i = topBound; i <= bottomBound; i++) {
                ret.push_back(matrix[i][rightBound]);
                currCount++;
            }
            if (currCount > targetCount) return ret;
            rightBound--;

            for (int i = rightBound; i >= leftBound; i--) {
                ret.push_back(matrix[bottomBound][i]);
                currCount++;
            }
            if (currCount > targetCount) return ret;
            bottomBound--;

            for (int i = bottomBound; i >= topBound; i--) {
                ret.push_back(matrix[i][leftBound]);
                currCount++;
            }
            if (currCount > targetCount) return ret;
            leftBound++;
        }
        return ret;
    }
};